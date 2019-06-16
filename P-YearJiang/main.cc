class Bonus {
  public:
    int getMost(vector<vector<int> > board) {
      vector<vector<int> > dp(6,vector<int>(6,0));
      dp[0][0] = board[0][0];
      for(int i = 1;i<6;i++){
        dp[i][0] = board[i][0]+dp[i-1][0];
        dp[0][i] = board[0][i]+dp[0][i-1];

      }
      for(int i = 1;i<6;i++){
        for(int j = 1;j<6;j++){
          dp[i][j] = (dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1])+board[i][j];

        }

      }
      return dp[5][5];

    }

};
