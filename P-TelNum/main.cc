#include<iostream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

unordered_map<char,char> all={{'A','2'},{'B','2'},{'C','2'},{'D','3'},{'E','3'},{'F','3'},{'G','4'},{'H','4'},{'I','4'},{'J','5'},{'K','5'},{'L','5'},{'M','6'},{'N','6'},{'O','6'},{'P','7'},{'Q','7'},{'R','7'},{'S','7'},{'T','8'},{'U','8'},{'V','8'},{'W','9'},{'X','9'},{'Y','9'},{'Z','9'}};

int main(){
  int num;
  while(cin>>num){
    string s;
    set<string> alls;
    while(num--){
      cin>>s;
      string back;
      for(size_t i=0;i<s.size();i++){
        if(s[i]=='-')
          continue;
        else if(s[i]>='A'&&s[i]<='Z'){
          back.push_back(all.find(s[i])->second);

        }else
          back.push_back(s[i]);

      }
      back.insert(3,1,'-');
      alls.insert(back);

    }
    for(auto it=alls.begin();it!=alls.end();it++)
      cout<<*it<<endl;
    alls.clear();
    cout<<endl;

  }

}
