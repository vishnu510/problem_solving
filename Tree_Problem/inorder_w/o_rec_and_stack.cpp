// threaded binary tree

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* builtTree(int val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder_without_rec(TreeNode* root){
    TreeNode* pre,*curr;
    if(root==NULL) return;
    curr = root;
    while (curr!=NULL)
    {
        if(curr->left==NULL){
            cout<<curr->val<<" ";
            curr = curr->right;
        }
        else{

            pre = curr->left;
            while (pre->right!=NULL && pre->right!=curr)
            {
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                cout<<curr->val<<" ";
                curr = curr->right;
            }
            
        }
    }
    
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
    inorder_without_rec(root);

    return 0;
}