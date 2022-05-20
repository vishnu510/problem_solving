// Problem Number :226. Invert Binary Tree
#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode* left,*right;
    TreeNode(int d){
        val = d;
        left = right = NULL;
    }
};
TreeNode* builtTree(int val){
    TreeNode* temp = new TreeNode(val);
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
    }
void printTree(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
}
int main(){
    TreeNode* root = builtTree(4);
    root->left = builtTree(2);
    root->right = builtTree(7);
    root->left->left = builtTree(1);
    root->left->right = builtTree(3);
    root->right->left = builtTree(6);
    root->right->right =builtTree(9);
    TreeNode* inverted = invertTree(root);
    printTree(inverted);
    
    return 0;
}