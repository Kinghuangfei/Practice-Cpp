#include<iostream>
#include<string>
using namespace std;

bool find(string& a,string& b,int& start,int& count){
  int pos = a.find(b,start);
  if(pos==-1)
    return false;
  count++;
  start = pos+b.size();
  return true;

}

int main(){
  string a,b;
  while(cin>>a>>b){
    int start = 0,count = 0;
    while(find(a,b,start,count)){}
    cout<<count<<endl;

  }

}
