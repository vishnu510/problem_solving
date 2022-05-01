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
TreeNode* invertTree(TreeNode* root) {
      if(root==NULL){
            return root;
        }
        else{
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        }
        return root;
    }
void printTree(TreeNode* root){
      if(root==NULL)  return;
      queue<TreeNode*> q;
      q.push(root);
      while(q.empty()==false){
          int count = q.size();
          while (count>0)
          {
              TreeNode* node = q.front();
              cout<<node->data<<" ";
              q.pop();
              if(node->left!=NULL) q.push(node->left);
              if(node->right!=NULL) q.push(node->right);
              count--;
          }
          
      }
    }
int main(){
    TreeNode*root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    TreeNode* res = invertTree(root);
    printTree(res);
}