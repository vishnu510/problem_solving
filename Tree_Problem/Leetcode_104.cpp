// Problem Number :Maximum Depth of Binary Tree
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

int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right)+1;
    }

int main(){
    TreeNode* root = builtTree(4);
    root->left = builtTree(2);
    root->right = builtTree(7);
    root->left->left = builtTree(1);
    root->left->right = builtTree(3);
    root->right->left = builtTree(6);
    root->right->right =builtTree(9);
    cout<<maxDepth(root);
   
    
    return 0;
}