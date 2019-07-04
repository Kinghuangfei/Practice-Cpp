#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int num;
  while(cin>>num){
    if(num!=0)
      cout<<(long)(pow(5,num)-4)<<" "<<(long)(pow(4,num)+num-4)<<endl;

  }
  return 0;

}

