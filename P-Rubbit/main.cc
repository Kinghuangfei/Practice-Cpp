#include<iostream>

using namespace std;

int main(){
  int month;
  while(cin>>month){
    int birth = 0,month1 = 0,month2=1;//可以生产、差一个月生产，差两个月生产；
    while(--month){
      birth+=month1;
      month1 = month2;
      month2 = birth;

    }
    int sum = birth+month1+month2;
    cout<<sum<<endl;

  }
  return 0;

}
