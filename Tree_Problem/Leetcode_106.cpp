// construct binary tree for given inorder and postorder traversal

#include<bits/stdc++.h>
using namespace std;
#define COUNT 10
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder,int istart,int iend,int pstart,int pend) 
    {
        if(istart>iend or pstart>pend){
            return NULL;
        }
        int val = postorder[pend];
        int i = istart;
        while(inorder[i]!=val) i++;
        TreeNode* root = new TreeNode;
        root->left = constructTree(inorder, postorder,istart,i-1,pstart,pstart+i-istart-1); 
        root->right = constructTree(inorder, postorder,i+1,iend,pend-(iend-i),pend-1);
        return root;
    }
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return constructTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        
    }
    
 
int main(){
   vector<int> inorder {9,3,15,20,7};
   vector<int> postorder  {9,15,7,20,3};
   TreeNode* root = buildTree(inorder,postorder);

}