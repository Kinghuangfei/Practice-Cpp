#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
  public:
    vector<double> averageOfLevels(TreeNode* root) {
      vector<vector<int> >every;
      vector<double> result;
      queue<TreeNode*> level;
      if(!root)
        return result;
      level.push(root);
      while(!level.empty()){
        int count  = level.size();
        vector<int> tmp;
        while(count>0){
          TreeNode* get = level.front();
          tmp.push_back(get->val);
          level.pop();
          if(get->left)
            level.push(get->left);
          if(get->right)
            level.push(get->right);
          count--;

        }
        every.push_back(tmp);

      }
      for(int i = 0;i<every.size();i++){
        double sum = 0;
        for(int j = 0;j<every[i].size();j++){
          sum+=every[i][j];

        }
        double finial = sum/every[i].size();
        result.push_back(finial);

      }
      return result;

    }

};

int main (){
  return 0;
}
