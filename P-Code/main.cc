#include<cstdio>
using namespace std;

int answer[10001]={1,2,3};
void InitAnswer(int* answer){
  for(int i = 3;i<10001;++i){
    answer[i]=answer[i-1]+answer[i-2];
    if(answer[i]>=10000)
      answer[i]%=10000;

  }

}

int main(){
  InitAnswer(answer);
  int n;
  while(scanf("%d",&n)!=EOF){
    while(n--){
      int num;
      scanf("%d",&num);
      printf("%04d",answer[num-1]);

    }
    printf("\n");

  }
  return 0;

}
