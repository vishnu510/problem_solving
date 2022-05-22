
// Problem Number :230. Kth Smallest Element in a BST
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

};
TreeNode* builtTree(int val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}
vector<int> nums;
vector<int> kthMax(TreeNode* root){
   if(!root) return {};
   kthMax(root->left);
   nums.push_back(root->val);
   kthMax(root->right);
   return nums;
}
int kthSmallest(TreeNode* root, int k) {
        vector<int> ans = kthMax(root);   
        return ans[k-1];
    }
    

    

int main(){
    TreeNode* root = builtTree(3);
    root->left = builtTree(1);
    root->right = builtTree(4);
    root->left->right =builtTree(2);
    cout<<kthSmallest(root,1);
    
    return 0;
}