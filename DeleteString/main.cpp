#include<iostream>
#include<string>

using namespace std;

int main(){
  string dest,src;
  while(getline(cin,dest)){
    getline(cin,src);
    for(int i = 0;i<src.size();i++){
      string temp;
      for(int j=0;j<dest.size();j++){
        if(dest[j]!=src[i]){
          temp.append(1,dest[j]);

        }

      }
      dest = temp;

    }
    cout<<dest<<endl;

  }
  return 0;

}
