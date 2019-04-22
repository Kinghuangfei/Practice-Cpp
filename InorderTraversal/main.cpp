#include<iostream>
#include<stack>
#include<vector>

using namespace  std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
};

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> back;
      stack<TreeNode*> Stack;
      TreeNode*cur = root;
      while(cur||!Stack.empty()){
        while(cur){
          Stack.push(cur);
          cur=cur->left;

        }
        cur = Stack.top();
        Stack.pop();
        back.push_back(cur->val);
        cur = cur->right;

      }
      return back;

    }

};

int main(){
  return 0;
}
