// write your code here cpp
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int Month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

string DigitToString(int num){
  string back;
  int flag=1;
  while(num>9){
    string in(1,(char)(num%10+'0'));
    back+=in;
    num/=10;
    flag =0;
  }
  string in(1,(char)(num+'0'));
  back+=in;
  if(flag)
    back+="0";
  reverse(back.begin(),back.end());
  return back;
}

void GetDays(string& s,string y,int month,int num,int start,int Day){
  for(int i = 1;i<month;i++){
    int j = Month[i];
    while(j--)
      start++;
  }
  start%=7;
  int d = 0,count=0,i=0;
  if(num==-1){
    for(d = 1,i=start;d<=Month[month];++d,++i){
      if((i%7)==(Day-1)){
        if((d+7-Day)>=Month[month])
          break;
      }
    }
  }
  else{
    for(d = 0,count=0,i=start;d<=Month[month]&&count<num;++d,++i){
      if((i%7)==(Day-1))
        count++;
    }
  }
  string m =DigitToString(month);
  string D =DigitToString(d);
  s+=y+"-"+m+"-"+D;
}

int main(){
  string year;
  while(cin>>year){
    string YD,Marting,President,Hero,Americain,Labor,Thanksgiving,Chremists;
    int year_num=0,start=5,flag=0;
    for(auto e:year)//获取数字年份
      year_num=year_num*10+e-'0';
    for(int i = 2000;i<year_num;i++){//得到每年第一天是礼拜几，2000年第一天是礼拜六
      if((i%400==0)||(i%4==0&&i%100!=0))
        ++start;
      ++start;
    }
    start%=7/*,start+1*/;//得到礼拜几(-1)；
    YD+=year+"-01-01";
    if((year_num%400==0)||(year_num%4==0&&year_num%100!=0)){
      flag = 1;
      Month[2]++;
    }
    GetDays(Marting,year,1,3,start,1);
    GetDays(President,year,2,3,start,1);
    GetDays(Hero,year,5,-1,start,1);
    Americain+=year+"-07-04";
    GetDays(Labor,year,9,1,start,1);
    GetDays(Thanksgiving,year,11,4,start,4);
    Chremists+=year+"-12-25";
    cout<<YD<<endl<<Marting<<endl<<President<<endl<<Hero<<endl;
    cout<<Americain<<endl<<Labor<<endl<<Thanksgiving<<endl<<Chremists<<endl<<endl;
    if(flag)
      Month[2]--;
  }
  return 0;
}

