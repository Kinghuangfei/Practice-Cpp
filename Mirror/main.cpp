#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

class Solution {
  public:
    void Mirror(TreeNode *pRoot) {
      queue<TreeNode*> q;
      if(pRoot)
        q.push(pRoot);
      while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        swap(cur->left,cur->right);
        if(cur->left)
          q.push(cur->left);
        if(cur->right)
          q.push(cur->right);
      }
    }
};

int main(){
  return 0;
}
