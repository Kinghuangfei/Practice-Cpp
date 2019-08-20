#include<iostream>

using namespace std;

class Hungry{
  public:
    static Hungry* GetInstance(){
      return &hun;
    }
  private:
    Hungry(){};
    Hungry(const Hungry& )=delete;
    Hungry& operator=(const Hungry&)=delete;
    static Hungry hun;
};

Hungry Hungry:: hun;
