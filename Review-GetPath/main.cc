/*
 * struct TreeNode {
 *  int val;
 *    struct TreeNode *left;
 *      struct TreeNode *right;
 *        TreeNode(int x) :
 *              val(x), left(NULL), right(NULL) {
 *                }
 *                };*/
class Solution {
  public:
    vector<vector<int>> back;
    void GoCheck(TreeNode* root,int num,int judge,vector<int>& in){
      if((!root)||judge>num)
        return;
      in.push_back(root->val);
      judge+=root->val;
      if(judge==num&&(!root->left)&&(!root->right)){
        back.push_back(in);
        in.pop_back();
        return;

      }
      GoCheck(root->left,num,judge,in);
      GoCheck(root->right,num,judge,in);
      in.pop_back();

    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
      vector<int> in;
      if(root){
        if(root->val>expectNumber)
          return back;
        GoCheck(root,expectNumber,0,in);

      }
      return back;

    }

};
*              }
* }
