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
      for(int i =0;i<4;i++){
        int new_x = x+action[i][0];
        int new_y = y+action[i][1];
        if(new_x<m&&new_x>=0&&new_y<n&&new_y>=0){
          Search(new_x, new_y,m,n);
        }
      }
      return;
    }
    int action[4][2]={{0,-1},{0,1},{-1,0},{1,0}};//上下左右;
    int count = 0;
};

int main(){
  Solution test;
  cout<<test.uniquePaths(2,3)<<endl;
  return 0;
}
