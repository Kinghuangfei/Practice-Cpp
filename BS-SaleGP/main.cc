class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i10 = 0, dp_i11 = (int)0x80000000;
        int dp_i20 = 0, dp_i21 = (int)0x80000000;
        for (auto price : prices) {
             dp_i20 = max(dp_i20, dp_i21 + price);
             dp_i21 = max(dp_i21, dp_i10 - price);
             dp_i10 = max(dp_i10, dp_i11 + price);
             dp_i11 = max(dp_i11, -price);
         }
         return dp_i20;
    }
};
