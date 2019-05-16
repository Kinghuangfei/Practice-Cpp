#include<iostream>

using namespace std;

class Solution {
  public:
    int  NumberOf1(int n) {
      int count = 0;
      while(n){
        count++;
        n = (n-1)&n;
      }
      return count;
    }
};

int main(){
  Solution test;
  cout<<test.NumberOf1(10)<<endl;
  return 0;
}
