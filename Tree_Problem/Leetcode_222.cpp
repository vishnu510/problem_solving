//count number of node in binary tree
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
int countNodes(TreeNode* root) {
       return root?(1+countNodes(root->left)+countNodes(root->right)):0;
    }
int main(){
    TreeNode*root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int ans = countNodes(root);
    cout<<ans;
}