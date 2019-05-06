#include<iostream>
#include<stdio.h>
#include<unistd.h>
using namespace std;

class Solution{
  public: 
    void ColorProccesBar(size_t size = 100){
      char round[4] ={'-','\\','|','/'}; 
      for(size_t i = 0;i<=size;++i){
          printf("%c[%%%d]",round[i%4],i);
        for(size_t j = 0;j<i;++j){
          if(i<=40)
          printf("\033[47;31m#\033[0m");
          else if(i>40&&i<=80)
          printf("\033[47;33m#\033[0m");
          else
          printf("\033[47;32m#\033[0m");
        }
        fflush(stdout);
        usleep(200000);
        printf("\r");
      }
      printf("\n");
  }
};

int main(){
  //int size = 0;
  //cin>>size;
  Solution().ColorProccesBar();
  return 0;
}
//////////////////////////////////////////////////
