//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
//注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      //dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
      //dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
      int dp_110=0,dp_120=0,dp_111=(int)0x80000000,dp_121=(int)0x80000000;
      for(int i = 0;i<prices.size();i++){
        int t110=dp_110;
        dp_110=max(dp_110,dp_111+prices[i]);
        dp_111=max(dp_111,-prices[i]);
        dp_120=max(dp_120,dp_121+prices[i]);
        dp_121=max(dp_121,dp_110-prices[i]);
      }
      return max(dp_110,dp_120);
    }
};
