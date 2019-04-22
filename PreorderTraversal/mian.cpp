#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> back;
      stack<TreeNode*> go;
      TreeNode*cur = root;
      while(cur||!go.empty()){
        while(cur){
          go.push(cur);
          back.push_back(cur->val);
          cur = cur->left;

        }
        cur = go.top();
        go.pop();
        cur = cur->right;

      }
      return back;

    }

};
