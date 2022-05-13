#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* builtTree(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
bool is_child_sum(TreeNode* root){
   
    if(root==NULL or(root->left==NULL and root->right==NULL)){
        return true;
    }
   int l = 0;
   int r = 0; 
   if(root->left!=NULL){
       l = root->left->data;
   }
   if(root->right!=NULL){
       r = root->right->data;
   }
   if((root->data == (l+r)) and is_child_sum(root->left) and is_child_sum(root->right)){
       return true;
   }
   else
      return false;
}
int main(){

    TreeNode* root = builtTree(20);
    root->left = builtTree(12);
    root->right = builtTree(8);
    root->left->left = builtTree(6);
    root->left->right = builtTree(6);
    root->right->left = builtTree(3);
    root->right->right = builtTree(5);
    root->right->right->left = builtTree(5);
    cout<<is_child_sum(root);
    return 0;
}