//Diameter of Binary Tree
// leetcode Problem level Easy
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
       int val;
       TreeNode *left;
       TreeNode *right;
};



TreeNode* buildTree(int val){
    TreeNode* temp = new TreeNode;
    temp->val =  val;
    temp->left = temp->right = NULL;
    return temp;
}    

void BinaryToDLL(TreeNode* root, TreeNode** head) 
{ 
    if (!root) 
        return; 
    BinaryToDLL(root->right, head); 
    root->right = *head; 
    if (*head) 
        (*head)->left = root; 
    *head = root; 
    BinaryToDLL(root->left, head); 
} 
void printList(TreeNode* head){
   while (head) 
    { 
        cout<<head->val<<"->"; 
        head = head->right; 
    } 
}
int main(){
     TreeNode* root = buildTree(1);
     root->left = buildTree(2);
     root->right = buildTree(3);
     root->left->left = buildTree(4);
     root->left->right = buildTree(5);
     TreeNode* head = NULL;
     BinaryToDLL(root,&head);
     printList(head);
     
    return 0;
}