
#include<iostream>
#include<string>

using namespace std;

string SumBit(string& num){
  string back="0";
  for(auto e:num){
    int sum = back[0]-'0'+e-'0',Up = sum/10;
    back[0]=sum%10+'0';
    for(size_t i = 1;i<back.size();i++){
      if(Up==0)
        break;
      int sum = back[i]-'0'+Up;
      Up = sum/10;
      back[i]=sum%10+'0';
    }
    if(Up)
      back+='1';
  }
  return back;
}

int main(){
  string num;
  while(cin>>num){
    do{
      num=SumBit(num);
    }while(num.size()>1);
    cout<<num<<endl;
  }
}
