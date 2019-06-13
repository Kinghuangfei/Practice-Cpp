#include<iostream>

using namespace std;

int PublicYue(int a,int b){
  int temp = 0;
  while(b){
    temp = a%b,a = b,b = temp;

  }
  return a;

}

int main(){
  int num,start;
  while(cin>>num>>start){
    while(num--){
      int monster;
      cin>>monster;
      start+=(monster<=start)?monster:PublicYue(monster,start);

    }
    cout<<start<<endl;

  }
  return 0;

}
