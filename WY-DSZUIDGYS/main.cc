#include<iostream>
#include<string>

using namespace std;

int GYS(int a,int b){
  int tmp;
  while(b!=0){
    tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

int main(){
  string s;
  while(cin>>s){
    int b=s[0],a;
    cin>>a;
    for(int i =1;i<(int)s.size();i++)
      b=(b*10-s[i]-'0')%a;
    cout<<GYS(a,b)<<endl;
  }
  return 0;
}
