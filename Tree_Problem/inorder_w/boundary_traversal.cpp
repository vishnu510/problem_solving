// Serialize and Deserialize Binary Tree
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
  };

TreeNode* builtTree(int val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

void printLeftBoundary(TreeNode* root){
  if (root == nullptr)
        return;
 
    if (root->left) {
 
        
        cout << root->val << " ";
        printLeftBoundary(root->left);
    }
    else if (root->right) {
        cout << root->val << " ";
        printLeftBoundary(root->right);
    }
}
void printRightBoundar(TreeNode* root)
{
    if (root == nullptr)
        return;
 
    if (root->right) {
        
        printRightBoundar(root->right);
        cout << root->val << " ";
    }
    else if (root->left) {
        printRightBoundar(root->left);
        cout << root->val << " ";
    }
   
}
void printLeaves(TreeNode* root)
{
    if (root == nullptr)
        return;
 
    printLeaves(root->left);
 
    
    if (!(root->left) && !(root->right))
        cout << root->val << " ";
 
    printLeaves(root->right);
}
void boundary_traversal(TreeNode* root){
  if(root==NULL) return;
  cout<<root->val<<" ";
  printLeftBoundary(root->left);
  printLeaves(root->left);
  printLeaves(root->right);
  printRightBoundar(root->right);

}

int main(){
      TreeNode* root =builtTree(10);
    root->left = builtTree(6);
    root->right = builtTree(15);
    root->left->left = builtTree(4);
    root->left->right = builtTree(7);
    root->left->right->left =builtTree(6);
    root->left->right->right =builtTree(9);
    root->right->left = builtTree(13);
    root->right->right =builtTree(20);
    boundary_traversal(root);
    
    return 0;
}