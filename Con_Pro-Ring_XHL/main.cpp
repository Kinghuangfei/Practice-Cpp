#include<iostream>
#include<pthread.h>
#include<vector>
#include<semaphore.h>

using namespace std;

class RingQueue{
  public:
    RingQueue(size_t cap=10)
      :_capacity(cap)
      ,RQ(cap)
    {
      sem_init(&lock,0,1);
      sem_init(&used,0,0);
      sem_init(&unused,0,_capacity);
    }
    ~RingQueue(){
      sem_destroy(&lock);
      sem_destroy(&used);
      sem_destroy(&unused);
    }
  public:
    void QueuePush(int data){
      sem_wait(&unused);
      sem_wait(&lock);
      RQ[write] = data;
      write = (write+1)%_capacity;
      sem_post(&lock);
      sem_post(&used);
    }
    void QueuePop(int* data){
      sem_wait(&used);
      sem_wait(&lock);
      *data = RQ[read];
      read = (read+1)%_capacity;
      sem_post(&lock);
      sem_post(&unused);
    }
  private:
    size_t  _capacity;
    vector<int> RQ;
    int read = 0;
    int write = 0;
    sem_t lock;
    sem_t used;
    sem_t unused;
};

void* thr_csm(void* arg){
  RingQueue* it = (RingQueue*)arg;
  while(1){
    int data;
    it->QueuePop(&data);
    cout<<"consumer"<<pthread_self()<<"get:"<<data<<endl;
  }
  return NULL;
}

void* thr_pro(void* arg){
  RingQueue* it = (RingQueue*)arg;
  int i = 0;
  while(1){
    it->QueuePush(i);
    cout<<"producter:"<<pthread_self()<<"putin:"<<i++<<endl;
  }
  return NULL;
}
int main(){
  RingQueue test;
  pthread_t pro[4],csm[4];
  for(int i = 0;i<4;i++){
   int ret= pthread_create(pro+i,NULL,thr_pro,(void*)&test);
   if(ret==-1){
     cout<<"pthread pro creat fail!\n";
   }
   ret=pthread_create(csm+i,NULL,thr_csm,(void*)&test);
   if(ret==-1){
     cout<<"pthread csm creat fail!\n";
   }
  }
  for(int i  =0;i<4;i++){
    pthread_join(pro[i],NULL);
    pthread_join(csm[i],NULL);
  }
  return 0;
}
