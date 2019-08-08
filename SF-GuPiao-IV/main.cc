//给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
//你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
//返回获得利润的最大值
class Solution {
  public:
    int maxProfit(vector<int>& prices, int fee) {
      int dp_10=0,dp_11=(int)0x80000000+fee;
      for(int i = 0;i<prices.size();i++){
        int tmp=dp_10;
        dp_10=max(dp_10,dp_11+prices[i]-fee);
        dp_11=max(dp_11,tmp-prices[i]);

      }
      return dp_10;

    }

};
