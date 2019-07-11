#include<iostream>

using namespace std;


int main(){
  int num;
  while(cin>>num){
    long a = 1,b=0,temp = 0;
    while(num--){
      temp = b;
      b = a+b;
      a = temp;

    }
    cout<<a+b<<endl;

  }
  return 0;

}
