#include<iostream>

using namespace std;

bool isPerfect(int num){
  int sum = 0;
  for(int i = 2;(i*i)<num;i++){
    if(num%i==0){
      sum+=i+num/i;

    }

  }
  if(sum == num-1)
    return true;
  return false;

}

int main(){
  int num;
  while(cin>>num){
    int count = 0;
    for(int i = 2;i<=num;i++){
      if(isPerfect(i))
        count++;

    }
    cout<<count<<endl;

  }
  return 0;

}
