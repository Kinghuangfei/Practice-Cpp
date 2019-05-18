#include<iostream>
#include<pthread.h>
#include<queue>
#include <unistd.h>

#define MAX_QUEUE 10

class BlockQueue{//对STL里的queue加上安全保护
  public:
    BlockQueue(size_t cap = MAX_QUEUE)
      : _capacity(cap)
    { 
      pthread_mutex_init(&_mutex,NULL);
      pthread_cond_init(&pro,NULL);
      pthread_cond_init(&con,NULL);
    }
    ~BlockQueue(){
      pthread_mutex_destroy(&_mutex);
      pthread_cond_destroy(&pro);
      pthread_cond_destroy(&con);
    }

    void QueuePush(int data){ 
      std::cout<<" "<<std::endl; 
      QueueLock();
      while (QueueIsFull()){
        std::cout<<"PushWait!"<<std::endl; 
        ProWait();
      }
      _queue.push(data);
      ConWakeUp();
      QueueUnLock();
    }

    void QueuePop(int* data){
      std::cout<<" "<<std::endl; 
      QueueLock();
      while (QueueIsEmpty()){
        std::cout<<"PopWait!"<<std::endl; 
        ConWait();
      }
      *data = _queue.front();
      _queue.pop();
      ProWakeUp();
      QueueUnLock();
    }

  public:
    void QueueLock(){//加锁
      pthread_mutex_lock(&_mutex);      
    }

    void QueueUnLock(){//解锁
      pthread_mutex_unlock(&_mutex);      
    }

    void ConWait(){
      pthread_cond_wait(&con,&_mutex);
    }

    void ConWakeUp(){//消费者唤醒
      pthread_cond_broadcast(&con);
    }

    void ProWait(){//生产者等待；
      pthread_cond_wait(&pro,&_mutex);
    }

    void ProWakeUp(){
      pthread_cond_broadcast(&pro);
    }

    bool QueueIsFull(){
      return (_capacity==_queue.size());
    }

    bool QueueIsEmpty(){
      return _queue.empty();
    }

  private:
    std::queue<int> _queue;
    size_t _capacity;//队列节点最大数量
    pthread_mutex_t _mutex;
    pthread_cond_t pro;
    pthread_cond_t con;
};

int count = 1;
pthread_mutex_t producer_lock;

void* producer(void* arg){
  std::cout<<"Producer create success!"<<std::endl; 
  BlockQueue* get = (BlockQueue*)arg;
  while(count){
    pthread_mutex_lock(&producer_lock);
    get->QueuePush(count);
    std::cout<<"Producer:"<<pthread_self()<<" put "<<count<<std::endl;
    count++;
    pthread_mutex_unlock(&producer_lock);
    usleep(200);
  }
  get->ConWakeUp();
  std::cout<<"Max Limit!Pro Exit"<<std::endl;
  pthread_exit(NULL);
  return NULL;
}

void* consumer(void*arg){
  std::cout<<"Comsumer create success!"<<std::endl; 
  BlockQueue* get = (BlockQueue*)arg;
  while(count){
    int data = 0;
    get->QueuePop(&data);
    std::cout<<"Consumer:"<<pthread_self()<<" get "<<data<<std::endl;
  }
  get->ProWakeUp();
  std::cout<<"Max Limit!Con Eixt"<<std::endl;
  pthread_exit(NULL);
  return NULL;
}
int main(){
  pthread_mutex_init(&producer_lock,NULL);
  pthread_t pro[4],con[4];
  int i;
  BlockQueue test;
  for(i =0;i<4;i++){
    int ret1 = pthread_create(pro+i,NULL,producer,(void*)&test);
    if(ret1){
      std::cout<<"prodect: pthread_create errno!"<<std::endl;
      return -1;
    }
    int ret2 = pthread_create(con+i,NULL,consumer,(void*)&test);
    if(ret2){
      std::cout<<"comsumer: pthread_create errno!"<<std::endl; 
      return -1;
    }
  }
  for(i =0;i<4;i++){
    pthread_join(pro[i],NULL);
    pthread_join(con[i],NULL);
  }
  return 0;
}
