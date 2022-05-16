//  Binary Tree Maximum Path Sum (Leetcode_124)
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
       int val;
       TreeNode *left;
       TreeNode *right;
};
void getTargetLeaf(TreeNode* root, int* max_sum_ref, 
                   int curr_sum, TreeNode** target_leaf_ref) 
{ 
    if (root == NULL) 
        return; 
    curr_sum = curr_sum + root->val; 
 
    if (root->left == NULL && root->right == NULL) { 
        if (curr_sum > *max_sum_ref) { 
            *max_sum_ref = curr_sum; 
            *target_leaf_ref = root; 
        } 
    } 
 
    getTargetLeaf(root->left, max_sum_ref, curr_sum, target_leaf_ref); 
    getTargetLeaf(root->right, max_sum_ref, curr_sum, target_leaf_ref); 
} 

bool printPath(TreeNode* root,TreeNode*targeleaf){
    if(root==NULL) return false;
    if(root==targeleaf or printPath(root->left,targeleaf) or printPath(root->right,targeleaf)){
        cout<<root->val<<" ";
        return true;
    }
    return false;
}
int maxPathSum(TreeNode* root) {
       if(root==NULL){
           return 0;
       }
       TreeNode* target_leaf;
       int max_sum = 0;
       cout<<"Maximum Path is: ";
       getTargetLeaf(root,&max_sum,0,&target_leaf);
       printPath(root,target_leaf);
       cout<<"\n"<<"Maximum Sum is: ";
       return max_sum;
    }
TreeNode* buildTree(int val){
    TreeNode* temp = new TreeNode;
    temp->val =  val;
    temp->left = temp->right = NULL;
    return temp;
}    

int main(){
     TreeNode* root = buildTree(-10);
     root->left = buildTree(9);
     root->right = buildTree(20);
     root->right->left = buildTree(15);
     root->right->right = buildTree(7);
     cout<<maxPathSum(root);
    return 0;
}