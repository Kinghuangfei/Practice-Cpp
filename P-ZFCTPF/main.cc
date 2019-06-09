#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  string src,dest;
  while(cin>>src>>dest){
    int signal  =1;
    vector<int> check(src.size(),0);
    for(int i = 0;(size_t)i<src.size();i++){
      if(src[i]=='?')
        check[i]=1;
      else if(src[i]=='*')
        check[i]=2;

    }
    for(int i = 0,j=0;(size_t)i<src.size()&&(size_t)j<dest.size();j++,i++){
      if(!check[i]){
        if(src[i]!=dest[j]){
          cout<<"false"<<endl,signal = 0;
          break;

        }

      }else if(check[i]==1){
        continue;

      }else{
        while(i<src.size()&&j<dest.size()&&src[i]!=dest[j]){
          j++,i++;

        }
        if(j>dest.size()){
          cout<<"false"<<endl,signal = 0;
          break;

        }

      }

    }
    if(signal)
      cout<<"true"<<endl;

  }
  return 0;

}
