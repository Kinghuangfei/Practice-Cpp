#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  while(cin>>s){
    int start = 0;
    int end = (size_t)s.size()-1;
    while(start<end){
      char tmp = s[start];
      s[start] = s[end];
      s[end] = tmp;
      start++;
      end--;

    }
    cout<<s<<endl;

  }
  return 0;

}
