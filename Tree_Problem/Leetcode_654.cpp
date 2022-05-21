
// Problem Number :654. Maximum Binary Tree
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

TreeNode* constructMaximumBinary(vector<int>& nums,int start,int end) {
        if(start>end) return NULL;
        int index =-1;
        int val = -1;
        for(int i =start;i<=end;i++){
            if(nums[i]>val){
                index = i;
                val = nums[i];
            }
        }
        TreeNode* root = builtTree(val);
        root->left = constructMaximumBinary(nums,start,index-1);
        root->right = constructMaximumBinary(nums,index+1,end);
        return root;
    }
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinary(nums,0,nums.size()-1);
    }
    
void printTree(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);

}

int main(){
    vector<int> nums{3,2,1,6,0,5};
    TreeNode* root = constructMaximumBinaryTree(nums);
    printTree(root);
    return 0;
}