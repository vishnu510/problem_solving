#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* buildTree(int val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}
int construct_sum_tree(TreeNode* root){
  if(root==NULL){
      return 0;
  }
  int l = construct_sum_tree(root->left);
  int r = construct_sum_tree(root->right);
  int v = root->val;
  root->val = l+r;
  return (l+r+v);
}
int main(){
    TreeNode* root = buildTree(10);
    root->left = buildTree(-1);
    root->right = buildTree(3);
    root->left->left = buildTree(4);
    root->left->right = buildTree(5);
    root->right->left = buildTree(-2);
    int ans = construct_sum_tree(root);
    return 0;
}