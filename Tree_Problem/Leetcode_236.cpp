#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* buildTree(int data){
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}
 int lowestCommonAncestor(TreeNode* root, int p, int q) {
     int left_search = 0;
     int right_search = 0;
     if(root==NULL){
         return 0;
     }
     if(root->val==p or root->val==q){
         return root->val;
     }
     left_search = lowestCommonAncestor(root->left,p,q);
     right_search = lowestCommonAncestor(root->right,p,q);
     if(left_search==0){
         return right_search;
     }
    if(right_search==0){
         return left_search;
     }
    return root->val;
  }

int main(){
    TreeNode* root = buildTree(3);
    root->left = buildTree(5);
    root->right = buildTree(1);
    root->left->left = buildTree(6);
    root->left->right = buildTree(2);
    root->left->right->left = buildTree(7);
    root->left->right->right = buildTree(4);
    root->right->left = buildTree(0);
    root->right->right = buildTree(8);
    cout<<lowestCommonAncestor(root,5,8);
    return 0;
}