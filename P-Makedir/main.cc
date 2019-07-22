nclude<iostream>
#include<set>
#include<vector>
#include<string>

using namespace std;

int main(){
  string pr("mkdir -p "),in;
  int num;
  while(cin>>num){
    set<string> all;
    vector<string> p;
    getline(cin,in);
    while(num--){
      getline(cin,in);
      all.insert(in);

    }
    for(auto it=all.begin();it!=all.end();++it){
      string back,s=*it;
      if(it!=all.begin()){
        back=p.back();
        if(back.size()&&(s.find(back)==0)&&(s[back.size()]=='/'))
          p.pop_back();

      }
      p.push_back(s);

    }
    for(auto e:p){
      string out=pr+e;
      cout<<out<<endl;

    }
    cout<<endl;

  }
  return 0;

}
