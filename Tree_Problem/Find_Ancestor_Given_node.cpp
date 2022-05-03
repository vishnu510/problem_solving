// Mirroring or Inverting the binary tree
// Level order tree Traversal

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int data;
  TreeNode * left;
  TreeNode * right;
 
};

TreeNode* newNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int printAncestors(TreeNode *root, int target) 
{ 
  if(!root) 
     return 0; 
  if(root->data == target) 
     return 1; 
 
  /* If target is present in either left or right subtree of this node, 
     then print this node */
  if(printAncestors(root->left, target) || printAncestors(root->right, target) ) 
  { 
    printf("%d ", root->data);
    return 1; 
  } 
  return 0; 
} 

int main(){
    TreeNode*root = newNode(10); 
  root->left        = newNode(20); 
  root->right       = newNode(30); 
  root->left->left  = newNode(40); 
  root->left->right = newNode(50); 
  root->left->left->left  = newNode(70); 
 
  printAncestors(root, 70); 
}