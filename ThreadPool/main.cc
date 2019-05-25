#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<queue>
#include<errno.h>

using namespace std;

typedef bool(* task_callback)(int data);

class Task{//任务类
  public:
    Task()
    { }
    Task(int data,task_callback handler)
      :_data(data)
      ,_handler(handler)
    { }
    ~Task()
    { }
  public:
    void SetTask(int data,task_callback handler){//手动添加任务；
      _data = data;
      _handler = handler;
    }
    bool Run(){
      return _handler(_data);
    }
  private:
      int _data;
      task_callback _handler;
};

#define MaxPool 5
#define MaxList 10

class ThreadPool{
  private:
    int max_thread;//最大线程数；
    int have_thread;//当前存在的线程数；
    queue<Task> WaitList;
    size_t _capacity;
    int quit_flag = false;
    pthread_cond_t pro;
    pthread_cond_t con;
    pthread_mutex_t Lock;
  private:
    void ListPush(Task t){
      WaitList.push(t);
    }
    void ListPop(Task* get){
      *get = WaitList.front();
      WaitList.pop();
    }
    void ListLock(){
      pthread_mutex_lock(&Lock);
    }
    void ListUnlock(){
      pthread_mutex_unlock(&Lock);
    }
    void ProWait(){
      pthread_cond_wait(&pro,&Lock);
    }
    void ProWakeUp(){
      pthread_cond_broadcast(&pro);
    }
    void ConWait(){
      if(quit_flag==true){
        have_thread--;
        cout<<"pthread:"<<pthread_self()<<" exit！"<<endl;
        pthread_mutex_unlock(&Lock);
        pthread_exit(NULL);
      }
      pthread_cond_wait(&con,&Lock);
    }
    void ConWakeUp(){
      pthread_cond_broadcast(&con);
    }
    bool IsFull(){
      return WaitList.size()==_capacity;
    }
    bool IsEmpty(){
      return WaitList.empty();
    }

  public:
    ThreadPool(int pth_num = MaxPool,int pth_que = MaxList)
      :max_thread(pth_num)
      ,have_thread(0)
      ,_capacity(pth_que)
    {
      pthread_cond_init(&pro,NULL);
      pthread_cond_init(&con,NULL);
      pthread_mutex_init(&Lock,NULL);
    }
    ~ThreadPool(){
      pthread_cond_destroy(&pro);
      pthread_cond_destroy(&con);
      pthread_mutex_destroy(&Lock);
    }
  public:
    static void* pth_start(void* arg){//为什莫必须是静态函数?:因为不是static就有this指针，而要求只能有一个参数
      ThreadPool*pool = (ThreadPool*)arg;
      while(1){
        pool->ListLock();
          while(pool->IsEmpty()){
            pool->ConWait();
          }
          Task t;//获取List中的task，消费者；
          pool->ListPop(&t);
          pool->ConWakeUp();
          pool->ListUnlock();
          t.Run();
      }
      return NULL;
    }
    bool PoolInit(){
      pthread_t* tpid = new pthread_t[max_thread];
      for(int i = 0;i<max_thread;i++){
        int ret = pthread_create(tpid+i,NULL,pth_start,(void*)this);
        if(ret<0){
          perror("pthread_create errno \n");
          return false;
        }
        have_thread++;
        pthread_detach(tpid[i]);
      }
      return true;
    }
    void AddTask(Task t){
      ListLock();
      while(IsFull()){
        ProWait();
      }
      ListPush(t);
      ConWakeUp();
      ListUnlock();
    }
    void ThrPoolQuit(){
      quit_flag = true;
      while(have_thread>0){
        ProWakeUp();
        usleep(1000);
      }
      return ;
    }
};

bool task_handler(int data){
  srand(time(NULL));
  int sec = rand()%7;
  cout<<"pthread:"<<pthread_self()<<"sleep"<<sec<<endl;
  sleep(sec);
  return true;
}

int main(){
  ThreadPool pool;
  Task t[MaxList];
  pool.PoolInit();
  for(int i = 0;i<10;i++){
    t[i].SetTask(i,task_handler);
    pool.AddTask(t[i]);
  }
  pool.ThrPoolQuit();
  return 0;
}
