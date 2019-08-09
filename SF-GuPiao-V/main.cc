class Solution {
  public:
    int maxProfit(int k, vector<int>& prices) {
      if(!prices.size())
        return 0;
      int dp_10=0,dp_11=(int)0x80000000,size=prices.size();
      if(k>size/2){
        for(int i =0 ;i<size;i++){
          int tmp = dp_10;
          dp_10=max(dp_10,dp_11+prices[i]);
          dp_11=max(dp_11,tmp-prices[i]);

        }
        return dp_10;

      }
      size++;
      vector<vector<vector<int>>> dp(size,vector<vector<int>>(k+1,vector<int>(2,0)));
      for(int i =0 ;i<size;i++){
        for(int j =1 ;j<=k;j++){
          if(i==0)
            dp[0][j][1]=dp[0][0][1]=(int)0x80000000;
          else{
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i-1]);
            dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i-1]);

          }

        }

      }
      int max = 0;
      for(int i = 1;i<=size;i++){
        max=max>dp[i-1][k][0]?max:dp[i-1][k][0];

      }
      return max;

    }

};
