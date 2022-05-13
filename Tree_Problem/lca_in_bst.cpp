// Find lowwest commen ancestor in binary Search tree
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int data;
  TreeNode * left;
  TreeNode * right;
 
};

TreeNode* buildTree(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int lca(TreeNode* root, int x,int y){

   if(root==NULL) 
   return 0;
   if(root->data>x and root->data>y){
       lca(root->left,x,y);
   }
   
   else if(root->data<x and root->data<y){
       lca(root->right,x,y);
   }
   else
     return root->data;
}
int main(){
    TreeNode* root = buildTree(10); 
  root->left        = buildTree(20); 
  root->right       = buildTree(30); 
  root->left->left  = buildTree(40); 
  root->left->right = buildTree(50); 
  root->left->left->left  = buildTree(70); 
  cout<<lca(root,20,50);

    return 0;
}
