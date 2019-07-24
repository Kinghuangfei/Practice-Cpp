#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  string a,b;
  while(cin>>a>>b){
    int A=a.size(),B=b.size();
    vector<vector<int>> dp(A+1,vector<int>(B+1,0));
    for(int i=1;i<=A;i++){
      for(int j=1;j<=B;j++){
        if(a[i-1]==b[j-1])
          dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i][j-1],dp[i-1][j]));
        else
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

      }

    }
    cout<<dp[A][B]<<endl;

  }
  return 0;

}
