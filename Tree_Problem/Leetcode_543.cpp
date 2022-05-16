//Diameter of Binary Tree
// leetcode Problem level Easy
#include<bits/stdc++.h>
using namespace std;
 int daimeter = INT_MIN;
struct TreeNode
{
       int val;
       TreeNode *left;
       TreeNode *right;
};

TreeNode* buildTree(int val){
    TreeNode* temp = new TreeNode;
    temp->val =  val;
    temp->left = temp->right = NULL;
    return temp;
}    
int max_height(TreeNode* root,int* diameter){
    if(root==NULL) return 0;
    int left = max_height(root->left,diameter);
    int right = max_height(root->right,diameter);
    *diameter = max(*diameter,left+right);
    return 1 + max(left,right);
}
int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diameter = INT_MIN;
        int height_of_Tree = max_height(root,&diameter);
        return diameter;
    }

int main(){
     TreeNode* root = buildTree(1);
     root->left = buildTree(2);
     root->right = buildTree(3);
     root->left->left = buildTree(4);
     root->left->right = buildTree(5);
     cout<<diameterOfBinaryTree(root);
    return 0;
}