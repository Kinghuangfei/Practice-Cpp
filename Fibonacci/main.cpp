#include<iostream>
using namespace std;

class Solution {
  public:
    int Fibonacci(int n) {
      int a=0,b=1,c=0;
      if (n==0){return 0;}
      else if(n==1){return b;}
      else{
        while(n>=2){
          c = a+b;
          a = b;
          b =c;
          n--;

        }
        return c;

      }

    }
    int Fibonacci2(int n) {
      if(n==0){return 0;}
      else if(n==1){return 1;}
      else if(n==2){return 1;}
      return Fibonacci(n-1)+Fibonacci(n-2);

    }

};

int main(){
  int n  = 0;
  cin>>n;
  Solution test;
  cout<<test.Fibonacci(n)<<endl;
  return 0;
}
