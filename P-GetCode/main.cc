// write your code here cpp
#include<iostream>

using namespace std;
int main (){
  string n;
  while(getline(cin,n)){
    for(size_t i = 0;i<n.size();i++){
      if(n[i]!=' '){
        int sub = n[i]-'A';
        if(sub>=5)
          n[i]=sub-5+'A';
        else
          n[i] = 21+sub+'A';
      }
    }
    cout<<n<<endl;
  }
  return 0;
}

