// Problem Number :112. Path Sum
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


    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        targetSum-=root->val;
        if(root->left==NULL and root->right==NULL){
            return targetSum==0;
        }
        return hasPathSum(root->left,targetSum) or hasPathSum(root->right,targetSum);
            
        
    }

int main(){
    TreeNode* root = builtTree(5);
    root->left = builtTree(4);
    root->right = builtTree(8);
    root->left->left = builtTree(11);
    root->left->left->left = builtTree(7);
    root->left->left->right = builtTree(2);
    root->right->left = builtTree(13);
    root->right->right =builtTree(4);
    root->right->right->right =builtTree(1);
    cout<<hasPathSum(root,22);
    
    return 0;
}