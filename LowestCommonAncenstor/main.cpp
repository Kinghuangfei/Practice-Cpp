#include<iostream>
#include<stack>

using namespace std;

struct TreeNode{
  int val;
  TreeNode*left;
  TreeNode*right;
};

class Solution {
  public:
    bool IsInsert(TreeNode*cur,TreeNode*node,stack<TreeNode*>& s){
      if(cur==nullptr)
        return false;
      s.push(cur);
      if(cur==node)
        return true;
//      当前不是要找的，去找左右孩子节点；
        if(IsInsert(cur->left,node,s))
          return true;
      if(IsInsert(cur->right,node,s))
        return true;
      //该节点及之后都不存在要找的路径，弹出；出栈
      s.pop();
      return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root==NULL){return NULL;}
      if(q==root||p==root){
        return root;

      }
      stack<TreeNode*> path1;
      stack<TreeNode*> path2;
      IsInsert(root,q,path1);
      IsInsert(root,p,path2);
      //裁剪路径到相同，因为根到公共祖先途径相等；
      while(path1.size()!=path2.size()){
        if(path1.size()>path2.size()){
          path1.pop();
        }else{
          path2.pop();
        }
      }
      //寻找第一个相同的节点，记为公共祖先；
      while(!path1.empty()){
        if(path1.top()==path2.top())
          return path1.top();
        path1.pop();
        path2.pop();
      }
      return NULL;
    }
};
