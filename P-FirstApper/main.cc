#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  string s;
  while(getline(cin,s)){
    vector<int> hash(128,0);
    string one;
    for(auto ss:s)
      hash[ss]++;
    for(size_t i = 0;i<hash.size();i++){
      if(hash[i]==1){
        one.push_back((char)i);

      }

    }
    if(!one.size())
      cout<<-1<<endl;
    else{
      char fin =0; 
      for(auto i:s){
        for(auto j:one){
          if(i==j){
            fin=i;
            break;

          }

        }
        if(fin)
          break;

      }
      cout<<fin<<endl;

    }

  }
  return 0;

}
