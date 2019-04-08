#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
  public:
    string addStrings(string num1, string num2) {
      int end1 = num1.size()-1,end2 = num2.size()-1;
      string ret;
     // ret.reserve(num1.size()>num2.size()?(num1.size()+1):(num2.size()+1));
      int go =0;
      while(end1>=0 || end2>=0){
        int v1 =0,v2=0,sum=0;
        if(end1>=0)
          v1 = num1[end1]-'0';

        if(end2>=0)
          v2 = num2[end2]-'0';

        sum = v1+v2+go;
        go =0;
        if(sum>=10){
          go = 1;
          sum-=10;
        }
       ret.insert(ret.begin(),sum+'0');
       // ret+=(sum+'0');
        end1--;
        end2--;
      }
      if(go==1){
       ret.insert(ret.begin(),'1');
       // ret+='1';
      }
      //algorithm::reverse(0,ret.size()-1,ret);
      return ret;
    }
};

int main(){
  Solution test;
  string a("123");
  string b("123");
  string c = test.addStrings(a,b);
  cout<<c.c_str()<<endl;
  return 0;
}
