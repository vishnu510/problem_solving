//938. Range Sum of BST
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
int sum =0;
int inorder(TreeNode* root,int L,int R){
   
    if(root){
        inorder(root->left,L,R);
        if(root->val>=L and root->val<=R){
            sum+=root->val;
        }
        inorder(root->right,L,R);
    }
    return sum;
}
 int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        return inorder(root,low,high);
        
    }

int main(){
    TreeNode* root = builtTree(10);
    root->left = builtTree(5);
    root->right = builtTree(15);
    root->left->left = builtTree(3);
    root->left->right = builtTree(7);
    root->right->right = builtTree(18);
    cout<<rangeSumBST(root,7,15);
 
    return 0;
}