#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> back;
        TreeNode* go=root;
        TreeNode* last;
        stack<TreeNode*> Stack;
        while(go||!Stack.empty()){
            while(go)
            {
            Stack.push(go);
            go = go->left;
            }
        TreeNode* Top = Stack.top();
        if(!Top->right){
            back.push_back(Top->val);
            Stack.pop();
            last = Top;
        }else if(Top->right==last){
             back.push_back(Top->val);
             Stack.pop();
             last = Top; 
        }else{
            go = Top->right;
        }
        }
        return back;
    }
};

int main(){
  return 0;
}
