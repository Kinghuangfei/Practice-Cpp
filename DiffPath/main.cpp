#include<iostream>

using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
      Search(0,0,m,n);
      return count;
    }
    void Search(int x, int y,int m,int n) {
      if(x==m-1&&y==n-1){
        count++;
        return;
      }
      for(int i =0;i<2;i++){
        int new_x = x+action[i][0];
        int new_y = y+action[i][1];
        if(new_x<m&&new_x>=0&&new_y<n&&new_y>=0){
          Search(new_x, new_y,m,n);
        }
      }
      return;
    }
    int action[2][2]={{0,1},{1,0}};//下右;
    int count = 0;
};

class Solution2 {
  public:
    int uniquePaths(int m, int n) {
      int** dp= new int*[m];
      for(int i = 0;i<m;i++){
        dp[i] = new int[n]; 
      }
      if(m==1||n==1) return 1;
      for(int i = 0;i<m;i++){
        dp[i][0] = 1;//第一行都只能从左边来；都是一种

      }
      for(int j = 0;j<n;j++){
        dp[0][j] = 1;//第一列都只能从上边来；都是一种

      }
      for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
          dp[i][j] = dp[i][j-1]+dp[i-1][j];//从左边来的可能加上从右边来的可能；

        }

      }
      return dp[m-1][n-1];//返回右下角那个的可能

    }

};

class Solution3 {
  public:
  int uniquePaths(int m, int n) {
    int** dp= new int*[m];
    for(int i = 0;i<m;i++){
      dp[i] = new int[n]; 
    }
    if(m==1||n==1) return 1;
    for(int i = 0;i<m;i++){
      dp[i][0] = 1;//第一行都只能从左边来；都是一种

    }
    for(int j = 0;j<n;j++){
      dp[0][j] = 1;//第一列都只能从上边来；都是一种

    }
    for(int i = 1;i<m;i++){
      for(int j = 1;j<n;j++){
        dp[i][j] = dp[i][j-1]+dp[i-1][j];//从左边来的可能加上从右边来的可能；

      }

    }
    return dp[m-1][n-1];//返回右下角那个的可能
  }
};

int main(){
  Solution test;
  Solution2 test2;
  cout<<test.uniquePaths(2,3)<<endl;
  cout<<test2.uniquePaths(2,3)<<endl;
  return 0;
}
