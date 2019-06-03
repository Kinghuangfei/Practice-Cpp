#include<iostream>

using namespace std;

int main(){
  int days_[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
  int year,month,day;
  while(cin>>year>>month>>day){
    int days = days_[month-1]+day;
    if(((year%4==0)&&(year%100))||(year%400==0))
      days+=1;
    cout<<days<<endl;

  }
  return 0;

}
