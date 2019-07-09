// write your code here cpp
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  int Fib[100001]={1,1,2};
  for(int i = 2;i<=100000;i++){
    Fib[i]=(Fib[i-1]+Fib[i-2])%1000000;
  }
  int num;
  while(cin>>num){
    if(num>31){
      cout<<setw(6)<<setfill('0')<<Fib[num]<<endl;
    }
    else
      cout<<Fib[num]<<endl;
  }
  return 0;
}

