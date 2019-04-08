#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  while(getline(cin,s)){
    size_t pos = s.rfind(' ');
    cout<<"Last word length is:"<<s.size()-1-pos<<endl;
  }
  return 0;
}
