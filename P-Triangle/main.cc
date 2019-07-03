#include<iostream>

using namespace std;

bool Check(double a,double b,double c){
  if((a+b)>c)
    return true;
  return false;

}

int main(){
  double a,b,c;
  while(cin>>a>>b>>c){
    if(Check(a,b,c)&&Check(a,c,b)&&Check(b,c,a))
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;

  }

}
