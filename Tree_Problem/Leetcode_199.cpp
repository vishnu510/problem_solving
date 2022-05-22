
// Problem Number :199. Binary Tree Right Side View
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

vector<int> rightSideView(TreeNode* root) {
     vector<int> nums;
     if(!root) return nums;
     queue<TreeNode*> q;
     q.push(root);
     while(!q.empty()){
         int n = q.size();
         
         for(int i=0;i<n;i++){
             TreeNode* curr = q.front();
             q.pop();
             if(i==n-1){
                 nums.push_back(curr->val);
             }
             if(curr->left) q.push(curr->left);
             if(curr->right) q.push(curr->right);
         }
     }
     return nums;
    }

    

int main(){
    TreeNode* root = builtTree(1);
    root->left = builtTree(2);
    root->right = builtTree(3);
    root->left->right =builtTree(5);
    root->right->right = builtTree(4);
    vector<int> answer = rightSideView(root);
    for(auto i:answer){
        cout<<i<<" ";
    }
    return 0;
}