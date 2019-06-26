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
    void TreeDepth1(TreeNode* pRoot,int count,int& Max){
      if(pRoot==NULL){
        Max = count>Max?count:Max;
        return;

      }
      count++;
      TreeDepth1(pRoot->left,count,Max);
      TreeDepth1(pRoot->right,count,Max);

    }
    int TreeDepth(TreeNode* pRoot)
    {
      int Max=0;
      TreeDepth1(pRoot,0,Max);
      return Max;

    }

};
