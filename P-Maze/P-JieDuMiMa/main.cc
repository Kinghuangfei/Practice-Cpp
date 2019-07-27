#include<iostream>
#include<string>

using namespace std;

int main(){
  string get;
  while(getline(cin,get)){
    string back;
    for(auto e:get){
      if(e>='0'&&e<='9')
        back.push_back(e);

    }
    cout<<back<<endl;

  }
  return 0;

}
