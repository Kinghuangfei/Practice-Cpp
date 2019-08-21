/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
      if(!vin.size())
        return NULL;
      int rootval=pre[0];
      int split=0;
      for(int i=0;i<vin.size();i++){
        if(rootval==vin[i]){
          split=i;
          break;

        }

      }
      TreeNode* root=new TreeNode(rootval);
      auto it_pre=pre.begin();
      auto it_vin=vin.begin();
      vector<int> a(it_pre+1,it_pre+split+1),b(it_vin,it_vin+split);
      vector<int>c(it_pre+1+split,pre.end()),d(it_vin+split+1,vin.end());
      root->left=reConstructBinaryTree(a,b);
      root->right=reConstructBinaryTree(c,d);
      return root;

    }

};
*   }
