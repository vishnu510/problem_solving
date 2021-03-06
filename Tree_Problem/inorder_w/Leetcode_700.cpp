// Problem Number :700( Search in a Binary Search Tree) 
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

TreeNode* searchBST(TreeNode* root, int val) {
        if(!root or root->val==val) return root;
        if(root->val>val){
            return searchBST(root->left,val);
        }
        if(root->val<val){
            return searchBST(root->right,val);
        }
    }
    // Seoond Approach
TreeNode* searchBST_1(TreeNode* root, int val) {
        while(root!=NULL and root->val!=val){
            if(root->val>val){
                root = root->left;
            }
            else{
                root = root->right;
            }
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
    TreeNode* root = builtTree(4);
    root->left = builtTree(2);
    root->right = builtTree(7);
    root->left->left = builtTree(1);
    root->left->right = builtTree(3);
    TreeNode* search_root = searchBST(root,2);
    printTree(search_root);
    cout<<"\n";
    TreeNode* search_root1 = searchBST_1(root,2);
    printTree(search_root1);
    return 0;
}