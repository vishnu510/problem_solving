//Merge Two Binary Trees
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
 TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        TreeNode* merge = new TreeNode(root1->val+root2->val);
        merge->left = mergeTrees(root1->left,root2->left);
        merge->right = mergeTrees(root1->right,root2->right);
        return merge;
    }

    void printTree(TreeNode* root){
        if(root==NULL) return;
        cout<<root->val<<" ";
        printTree(root->left);
        printTree(root->right);
    }
int main(){
    TreeNode* root1 = builtTree(1);
    root1->left = builtTree(3);
    root1->right = builtTree(2);
    root1->left->left = builtTree(5);
    TreeNode* root2 = builtTree(2);
    root2->left = builtTree(1);
    root2->right = builtTree(3);
    root2->left->right = builtTree(4);
    root2->right->right = builtTree(7);

    TreeNode* Merge = mergeTrees(root1,root2);
    printTree(Merge);
    return 0;
}