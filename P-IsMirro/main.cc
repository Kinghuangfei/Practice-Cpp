/*
 * struct TreeNode {
 *     int val;
 *         struct TreeNode *left;
 *             struct TreeNode *right;
 *                 TreeNode(int x) :
 *                             val(x), left(NULL), right(NULL) {
 *                                 }
 *                                 };
 *                                 */
class Solution {
  public:
    bool isSymmetrical(TreeNode* pRoot)
    {
      if(!pRoot)
        return true;
      return Mirro(pRoot->left,pRoot->right);

    }
    bool Mirro(TreeNode* l,TreeNode* r){
      if(l==NULL)
        return r==NULL;
      else if(r==NULL)
        return false;
      else if(l->val!=r->val)
        return false;
      return Mirro(l->left,r->right)&&Mirro(l->right,r->left);

    }


};
*                             }
* }
