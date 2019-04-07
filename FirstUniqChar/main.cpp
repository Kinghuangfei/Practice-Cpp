//给定一个只有小写字母的字符串，找到他第一个不重复的字符，并返回他的索引，如果不存在，则返回-1；
#include<iostream>
#include<string>
using namespace std;

class Solution{
  public:
    int firstUniqChar(string s){
      int hashtab[256] = {0};
      for(size_t c = 0;c<s.size();++c){
        hashtab[s[c]-'a']++;
      }
      for(size_t i = 0;i<s.size();++i){
        if(hashtab[s[i]-'a']==1){
          return i;
          break;
        }
      }
      return -1;
    }
};

int main(){
  string s;
  cin>>s;
  Solution test;
  cout<<test.firstUniqChar(s)<<endl;
  return 0;
}
