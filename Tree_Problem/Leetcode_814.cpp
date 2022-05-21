
// Problem Number :814. Binary Tree Pruning
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

TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
       root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left==NULL and root->right==NULL and root->val==0){
            return NULL;
        }
        return root;
    }

    
void printTree(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);

}

int main(){
    TreeNode* root = builtTree(1);
    root->right = builtTree(0);
    root->right->left = builtTree(0);
    root->right->right = builtTree(1);
    pruneTree(root);
    printTree(root);
    return 0;
}