class Solution {
  public:
    int minPathSum(vector<vector<int> > &grid) {
      if(grid.size()==0||grid[0].size()==0)
        return 0;
      int size=grid.size(),row=grid[0].size();
      vector<vector<int>> s(size,vector<int>(row,0));
      s[0][0]=grid[0][0];
      for(int i=1;i<row;i++)
        s[0][i]=s[0][i-1]+grid[0][i];
      for(int i=1;i<size;i++)
        s[i][0]=s[i-1][0]+grid[i][0];
      for(size_t i=1;i<size;i++)
        for(size_t j=1;j<row;j++)
          s[i][j]=min(s[i-1][j],s[i][j-1])+grid[i][j];
      return s[size-1][row-1];

    }

};
