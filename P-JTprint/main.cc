#include<iostream>
#include<pthread.h>
#include <unistd.h>

class Print{
  public:
    Print(int K):k(K)
  {}
    ~Print(){
      pthread_mutex_destroy(&lock1);
      pthread_mutex_destroy(&lock2);
      pthread_cond_destroy(&fir);
      pthread_cond_destroy(&sec);
    }
    void Init(){
      pthread_mutex_init(&lock1,NULL);
      pthread_mutex_init(&lock2,NULL);
      pthread_cond_init(&fir,NULL);
      pthread_cond_init(&sec,NULL);
    }
  public:
    pthread_mutex_t lock1;
    pthread_mutex_t lock2;
    pthread_cond_t fir;
    pthread_cond_t sec;
    int k;
    int base=0;
};


void* fun1(void * arg){
  Print* p=(Print*)arg;
  while(1){
    while(p->base%2==1||p->base>p->k){
      pthread_cond_signal(&p->sec);
      if(p->base>p->k){
        std::cout<<"pthread1 exit\n"<<std::endl;
        pthread_exit(NULL);
      }
      pthread_cond_wait(&p->fir,&p->lock1);
    }
    std::cout<<"Pthread 1-"<<pthread_self()<<":"<<p->base<<std::endl;
    p->base+=1;
  }
  return NULL;
}

void* fun2(void * arg){
  Print* p=(Print*)arg;
  while(1){
    while(p->base%2==0||p->base>p->k){
      pthread_cond_signal(&p->fir);
      if(p->base>p->k){
        std:: cout<<"pthread2 exit\n"<<std::endl;
        pthread_exit(NULL);
      }
      pthread_cond_wait(&p->sec,&p->lock2);
    }
    std::cout<<"Pthread 2-"<<pthread_self()<<":"<<p->base<<std::endl;
    p->base+=1;
  }
  return NULL;
}

int main(){
  int k;
  std::cin>>k;
  pthread_t tid[2];
  Print p(k);
  p.Init();
  pthread_create(tid,NULL,fun1,(void*)&p);
  pthread_create(tid+1,NULL,fun2,(void*)&p);
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
  return 0;
}

