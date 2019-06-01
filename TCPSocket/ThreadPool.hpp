#include<iostream>
#include<queue>
#include<pthread.h>




typedef void(*Service)(int);
class Task{
  public:
    Task(int sock_=0,Service serv_=0):sock(sock_),serv(serv_)
    {}
    ~Task()
    {}
    void Run(){
      serv(sock);
    }
  private:
    int sock;
    Service serv;
};

class ThreadPool{
  private:
    int max_threads;
    int now_threads;
    int capacity;
    std::queue<Task> task_queue;
    pthread_mutex_t lock;
    pthread_cond_t cond;
  private:
    void LockQueue(){
      pthread_mutex_lock(&lock);
    }
    void UnlockQueue(){
      pthread_mutex_unlock(&lock);
    }
    bool isEmpty(){
      return !(task_queue.size());
    }
    void IdleThread(){
      pthread_cond_wait(&cond,&lock);
    }
    void TaskPop(Task& t){
      t = task_queue.front();
      task_queue.pop();
    }
    void WakeupOneThread(){
      pthread_cond_signal(&cond);
    }
  public:
    ThreadPool(int nums_=5):max_threads(nums_),now_threads(0){
      pthread_mutex_init(&lock,NULL);
      pthread_cond_init(&cond,NULL);
    }
    ~ThreadPool(){
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&cond);
    }
    void InitTheadPool(){
      pthread_t tpid[max_threads];
      for(auto i = 0;i<max_threads;i++){
        pthread_create(&tpid[i],NULL,ThreadRoutine,(void*)this);
        now_threads++;
      }
    }
    static void* ThreadRoutine(void * arg){
      ThreadPool* is = (ThreadPool*)arg;
      pthread_detach(pthread_self());
      for(;;){
        is->LockQueue();
        while(is->isEmpty()){
         is-> IdleThread();
        }
        Task t;
        is->TaskPop(t);
        is->UnlockQueue();
        t.Run();
      }
      return NULL;
    }
    void AddTask(const Task& t){
      LockQueue();
      task_queue.push(t);
      WakeupOneThread();
      UnlockQueue();
    }
};
