// check two trees are identical or not
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

  int data;
  TreeNode * left;
  TreeNode * right;
 
};

TreeNode* newNode(int data){
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q){
            return 1;
        }
        if(p and q){
            return (p->data==q->data) and isSameTree(p->right,q->right) and isSameTree(p->left,q->left);
        }
        return 0;
    }
int main(){
    TreeNode*root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    TreeNode*root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(5);
    root2->left->right = newNode(5);
    bool ans  = isSameTree(root1,root2);
    cout<<ans;
}