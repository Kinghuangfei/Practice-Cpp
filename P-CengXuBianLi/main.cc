
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
    val(x), left(NULL), right(NULL) {

    }

};
class Solution {
  public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
      vector<int> back;
      queue<TreeNode*> go;
      if(root==NULL)
        return back;
      go.push(root);
      while(go.size()){
        TreeNode* T = go.front(),* left = T->left,*right = T->right;
        go.pop();
        back.push_back(T->val);
        if(left)
          go.push(left);
        if(right)
          go.push(right);

      }
      return back;

    }

};
