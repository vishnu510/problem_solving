
// Problem Number :98. Validate Binary Search Tree
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
 bool check(TreeNode* root,TreeNode* lower,TreeNode *upper){
   if(!root) return true;
   if(lower and root->val<=lower->val) return false;
   if(upper and root->val>=upper->val) return false;
   return check(root->left,lower,root) and check(root->right,root,upper);

 }
 bool isValidBST(TreeNode* root) {

        return check (root,NULL,NULL);
    }


int main(){
    TreeNode* root = builtTree(2);
    root->right = builtTree(3);
    root->left = builtTree(1);
    cout<<isValidBST(root);
    
    return 0;
}