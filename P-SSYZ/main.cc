// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool ISS(int num){
  for(int i = 2;i*i<=num;i++){
    if(num%i==0)
      return false;
  }
  return true;
}

void Get(vector<int>& v,int& num){
  for(int i = 2;i*i<=num;i++){
    if(num%i==0&&ISS(i)){
      v.push_back(i);
      num/=i;
      Get(v,num);
      break;
    }
  }
  return;
}
string DigitToString(int n){
  string back;
  while(n>9){
    back.push_back(n%10+'0');
    n/=10;
  }
  back.push_back(n+'0');
  reverse(back.begin(),back.end());
  return back;
}

int main(){
  string num;
  while(cin>>num){
    int n = 0;
    string put(num);
    for(auto e:num){
      n=n*10+(e-'0');
    }
    vector<int> all ;
    Get(all,n);
    if(n!=1)
      all.push_back(n);
    for(size_t i = 0;i<all.size();i++){
      string in = DigitToString(all[i]);
      if(i==0)
        put+=" = "+in;
      else
        put+=" * "+in;
    }
    cout<<put<<endl;
  }
  return 0;
}

