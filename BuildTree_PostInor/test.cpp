#include<iostream>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
};

Node* BuildTree(char inorder[],char Postorder[],int size){
  if(size==0){return NULL;}
  int root_val = Postorder[size-1];
  int r = 0;
  for(int i =0;i<size;i++){
    if(inorder[i]==root_val){
      i = r;
      break;
    }
  }
  Node* root = (Node*)malloc(sizeof(Node));
  root->val = root_val;
  root->left = BuildTree(inorder,Postorder,r);
  root->right = BuildTree(inorder+r,Postorder+r+1,size-r-1);
  return root;
}

int main(){
  char inorder[] = {};
  char Postorder[] = {};
  int size = sizeof(inorder)/sizeof(inorder[0]);
  Node* back =BuildTree(inorder,Postorder,size);
  return 0;
}
