#include<iostream>
#include<vector>

using namespace std;

int main(){
  int num;
  while(cin>>num){
    vector<long> dp(num,0);
    dp[1]=1;
    for(int i=2;i<num;i++){
      dp[i]=(dp[i-2]+dp[i-1])*i;

    }
    cout<<dp[num-1]<<endl;

  }
  return 0;

}
