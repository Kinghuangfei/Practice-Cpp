#include<iostream>
#include<stdio.h>
using namespace std;

class Base{
  void virtual fun1(){cout<<"Base::fun1"<<endl;}
  void virtual fun2(){cout<<"Base::fun2"<<endl;}
  private:
  int _a;
};
class Base2{
  void virtual fun1(){cout<<"Base2::fun1"<<endl;}
  void virtual fun2(){cout<<"Base2::fun2"<<endl;}
  private:
  int _a2;

};
class Son : public Base{
  public:
    void virtual fun1(){cout<<"Son::fun1"<<endl;}
    void virtual fun3(){cout<<"Son::fun3"<<endl;}
  private:
    int _b;

};
typedef void (*VtFun)();

void PrintfVF(VtFun arr[]){
  printf("虚表:%p\n",arr);
  while(*arr!=NULL){
    VtFun vf = *arr;//存的函数指针
    printf("0x%p",vf);
    vf();//调用对应函数；
    cout<<endl;
    ++arr;

  }

}

int main(){
  Base father;
  Base2 father2;
  Son son;
  Base2* pb2 = &father2;//此时编译器帮我们自动进行了地址偏移，已经指向了继承base2类的虚表的位置
  PrintfVF( (VtFun*)*(int*)&father);
  PrintfVF( (VtFun*)*(int*)&son);//打印出了son指向father1的虚表
  PrintfVF( (VtFun*)*(int*)pb2);//打印son指向father2的虚表；
  PrintfVF( (VtFun*)*(int*)((char*)&son+sizeof(Base)));//手动偏移到指向Base2虚表的位置;
  return 0;

}//子类现在有20个字节_a1+_a2+_b+_vptr[0]+_vptr[1]=20个字节
