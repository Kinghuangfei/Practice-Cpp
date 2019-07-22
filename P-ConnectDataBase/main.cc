#include<iostream>
#include<string>

using namespace std;

int main(){
  int num;
  while(cin>>num){
    int cap=0,use=0;
    string id,act; 
    while(num--){
      cin>>id>>act;
      if(act=="connect"){
        use++;
        if(use>cap)
          cap++;

      }else{
        if(use>0)
          use--;

      }

    }
    cout<<cap<<endl;

  }
  return 0;

}
