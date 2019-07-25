#include<iostream>
#include<vector>

using namespace std;

int main(){
  int num,in;
  while(cin>>num){
    vector<int> len(num,0);
    for(int i=0;i<num;i++){
      cin>>in;
      len[i]=in;

    }
    vector<int>dp(num,1);
    for(int i=1;i<num;i++){
      for(int j=0;j<i;j++){
        if(len[i]>len[j])
          dp[i]=dp[j]+1>dp[i]?dp[j]+1:dp[i];

      }

    }
    int max=1;
    for(auto e:dp)
      max=max>e?max:e;
    cout<<max<<endl;

  }
  return 0;

}
