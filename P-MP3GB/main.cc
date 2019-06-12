#include<iostream>
#include<string>

using namespace std;

int main(){
  int num;
  while(cin>>num){
    string act,tmp;
    getline(cin,tmp);
    getline(cin,act);
    int start=1,pos = 1;
    for(auto e:act){
      if(e=='U'){
        if(pos ==1)
          pos = num,start=num-3;
        else{
          pos--;
          if(pos<start)
            start=pos;

        }

      }else{
        if(pos==num)
          pos = 1,start = 1;
        else{
          pos++;
          if(pos-start>3)
            start++;

        }

      }

    }
    if(num<4)
      start = 1;
    for(int i = 0;i<(num<4?num:4);i++){
      cout<<start+i;
      if(i!=3)
        cout<<' ';

    }
    cout<<endl;
    cout<<pos<<endl;

  }
  return 0;

}
