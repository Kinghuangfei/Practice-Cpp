#include<iostream>
#include<mutex>
#include<thread>

class Singleton{
  public:
    static volatile Singleton* GetInstance(){
      if(lazy==nullptr){
        lock.lock();
        if(lazy==nullptr)
          lazy=new Singleton;
        lock.unlock();
      }
      return lazy;
    }
    class GC{
      public:
        ~GC(){
          if(lazy)
            delete lazy;
        }
    };
    static GC gc;
  private:
    Singleton(){};
    Singleton(const Singleton& )=delete;
    Singleton& operator=(const Singleton&)=delete;
    static volatile Singleton* lazy;
    static std::mutex lock;
};

std::mutex Singleton::lock;
volatile Singleton* Singleton::lazy=nullptr;
static Singleton::GC gc;
