#include<iostream>
using namespace std;

long Fib[80]={1,1};

int main(){
  for(int i = 2;i<80;i++){
    Fib[i]=Fib[i-1]+Fib[i-2];

  }
  int a,b;
  while(cin>>a>>b){
    long final = 0;
    for(int i = a;i<=b;i++)
      final+=Fib[i-1];
    cout<<final<<endl;

  }
  return 0;

}
