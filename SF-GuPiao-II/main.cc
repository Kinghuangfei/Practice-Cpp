//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      //dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
      //dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
      int dp_10=0,dp_11=(int)0x80000000;
      for(int i = 0;i<prices.size();i++){
        int tmp=dp_10;
        dp_10=max(dp_10,dp_11+prices[i]);
        dp_11=max(dp_11,tmp-prices[i]);
      }
      return dp_10;
    }
};
