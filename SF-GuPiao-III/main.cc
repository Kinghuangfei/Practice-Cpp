//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
//设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
//你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      //dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
      //dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i]);
      int dp_10=0,dp_20=0,dp_11=(int)0x80000000;
      for(int i = 0;i<prices.size();i++){
        int tmp=dp_20;
        dp_20=dp_10;
        dp_10=max(dp_10,dp_11+prices[i]);
        dp_11=max(dp_11,tmp-prices[i]);
      }
      return dp_10;
    }
};
