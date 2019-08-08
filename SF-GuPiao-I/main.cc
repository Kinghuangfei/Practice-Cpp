//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//注意你不能在买入股票前卖出股票。
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int dpi0=0,dpi1=(int)0x80000000;
      for(int i = 0;i<prices.size();i++){
        dpi0=max(dpi0,dpi1+prices[i]);
        dpi1=max(dpi1,-prices[i]);

      }
      return dpi0;

    }

};
