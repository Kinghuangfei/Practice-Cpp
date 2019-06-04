#include<iostream>

using namespace std;

int main(){
  int m;
  int count = 0;
  cin>>m;
  while(m){
    count++;
    m&=m-1;
  }
  cout<<count<<endl;
  return 0;
}
