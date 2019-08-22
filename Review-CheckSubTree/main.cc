/*struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
    val(x), left(NULL), right(NULL) {

    }

};*/
class Solution {
  public:
    bool check(TreeNode* pRoot1, TreeNode* pRoot2){
      if(!pRoot2)//注意这里pRoot2为空了，但pRoot1还不一定结束，但pRoot1先结束了那一定不是子树
        return true;
      if(!pRoot1)
        return false;
      return (pRoot1->val==pRoot2->val)&&check(pRoot1->left,pRoot2->left)&&check(pRoot1->right,pRoot2->right);

    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
      if(pRoot1==NULL||pRoot2==NULL)
        return false;
      if(pRoot1->val==pRoot2->val)
        if(check(pRoot1,pRoot2))
          return true;
      return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);

    }

};
