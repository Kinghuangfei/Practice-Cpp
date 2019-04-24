#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
};


class Solution {
  public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
      vector<vector<int> > back;
      queue<TreeNode*> level;
      if(!root)
        return back;
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
        back.push_back(tmp);

      }
      reverse(back.begin(),back.end());
      return back;

    }

};

int main(){
  return 0;
}
