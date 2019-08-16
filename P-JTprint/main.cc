#include<iostream>
#include<pthread.h>

using namespace std;

class Print{
  public:
    Print(int K):k(K)
  {}
    ~Print(){
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&fir);
      pthread_cond_destroy(&sec);
    }
    void Init(){
      pthread_mutex_init(&lock,NULL);
      pthread_cond_init(&fir,NULL);
      pthread_cond_init(&sec,NULL);
    }
  public:
    pthread_mutex_t lock;
    pthread_cond_t fir;
    pthread_cond_t sec;
    int k;
    int base=0;
    int flag=0;
};


void* fun1(void * arg){
  Print* p=(Print*)arg;
  while(1){
    while(p->base%2==1){
      if(p->base>p->k){
        pthread_cond_broadcast(&p->sec);
        cout<<"pthread1 exit\n"<<endl;
        pthread_exit(NULL);
      }
      pthread_cond_signal(&p->sec);
      pthread_cond_wait(&p->fir,&p->lock);
    }
    cout<<"Pthread 1-"<<pthread_self()<<":"<<p->base<<endl;
    p->base+=1;
  }
  return NULL;
}

void* fun2(void * arg){
  Print* p=(Print*)arg;
  while(1){
    while(p->base%2==0||p->base>p->k){
      if(p->base>p->k){
        pthread_cond_broadcast(&p->fir);
        cout<<"pthread2 exit\n"<<endl;
        pthread_exit(NULL);
      }
      if(p->base){
        pthread_cond_signal(&p->fir);
      }
      pthread_cond_wait(&p->sec,&p->lock);
    }
    cout<<"Pthread 2-"<<pthread_self()<<":"<<p->base<<endl;
    p->base+=1;
  }
  return NULL;
}

int main(){
  int k;
  cin>>k;
  pthread_t tid[2];
  Print p(k);
  p.Init();
  pthread_create(tid,NULL,fun1,(void*)&p);
  pthread_create(tid+1,NULL,fun2,(void*)&p);
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
  return 0;
}

