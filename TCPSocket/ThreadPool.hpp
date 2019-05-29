#include<iostream>
#include<queue>
#include<pthread.h>




typedef void(*Service)(int);
class Task{
  public:
    Task(int sock_,Service serv_):sock(sock_),serv(serv_)
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
    int now_threads;
    int max_threads;
    int capacity;
    std::queue<Task> task_queue;
    pthread_mutex_t lock;
    pthread_cond_t cond;
  public:
    ThreadPool();
    ~ThreadPool();
    void InitTheadPool();
    static void* ThreadRoutine(void * arg){
      return NULL;
    }
    void AddTask(const Task& t){

    }
};
