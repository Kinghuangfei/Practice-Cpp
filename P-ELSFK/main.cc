#include<iostream>
#include<vector>
using namespace std;

int main(){
  int len;
  while(cin>>len){
    int num;
    cin>>num;
    vector<int> all(len,0);
    while(num--){
      int in;
      cin>>in;
      all[in-1]++;

    }
    int min=all[0];
    for(auto e:all){
      min=e<min?e:min;

    }
    cout<<min<<endl;

  }
  return 0;

}
