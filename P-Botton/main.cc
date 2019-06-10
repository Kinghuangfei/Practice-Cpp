#include<iostream>

using namespace std;

void count (int num){
  int yu = 0,kong = num,fresh = 0,drink = 0;
  do{
    drink+=fresh;
    kong += fresh+yu;
    fresh = kong/3;
    yu = kong%3;
    kong = 0;

  }while(fresh);
  if (yu==2)
    drink+=1;
  cout<<drink<<endl;

}

int main(){
  int num;
  while(cin>>num){
    if(num){
      count(num);

    }

  }
  return 0;

}
