#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> vv;
      vv.resize(numRows);
      for(int i = 0;i<numRows;i++){
        vv[i].resize(1+i,1);

      }
      for(int i = 0;i<vv.size();++i){
        for(int j = 0;j<vv[i].size();j++){
          if((j-1>=0)&&(j<=i-1)){
            vv[i][j] = vv[i-1][j-1]+vv[i-1][j];
          }
        }
      }
      return vv;
    }
};
