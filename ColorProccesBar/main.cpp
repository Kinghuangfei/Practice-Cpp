#include<iostream>
#include<stdio.h>
#include<unistd.h>
using namespace std;

class Solution{
  public: 
    void ColorProccesBar(size_t size = 20){
      for(size_t i = 0;i<size;++i){
        for(size_t j = 0;j<i;++j){
          int a = (i%7)+30;
          printf("\033[47;%dm#\033[0m",a);
        }
        fflush(stdout);
        usleep(500000);
        printf("\r");
      }
  }
};

int main(){
  //int size = 0;
  //cin>>size;
  Solution().ColorProccesBar();
  return 0;
}
