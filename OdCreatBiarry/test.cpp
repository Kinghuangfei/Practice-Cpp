#include<iostream>
using namespace std;

struct Node{
  int val;
  Node*left;
  Node*right;
};

struct Result{
  int used ;
  Node*root;
};

Result OdCreatrBinary(char Preorder[],int size){
  if(size==0){
    return (Result){0,NULL};
  }
  if(Preorder[0]=='#'){
    return (Result){1,NULL};
  }
  Node* root = (Node*)malloc(sizeof(Node));
  root->val = Preorder[0]-'0';
  Result left = OdCreatrBinary(Preorder+1,size-1);
  Result right = OdCreatrBinary(Preorder+1+left.used,size-left.used-1);
  root->left = left.root;
  root->right = right.root;
  return (Result){left.used+right.used,root};
}

int main(){
  char Preorder[] = {'1','2','3','5','7'};
  int size  = sizeof(Preorder)/sizeof(Preorder[0]);
  Result back = OdCreatrBinary(Preorder,size);
  return 0;
}
