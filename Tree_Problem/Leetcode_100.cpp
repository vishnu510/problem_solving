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
// recusive method extra stack space in worst case O(n)
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q){
            return 1;
        }
        if(p and q){
            return (p->data==q->data) and isSameTree(p->right,q->right) and isSameTree(p->left,q->left);
        }
        return 0;
    }

    // Iterative Method no extra space time is O(n) only and space is O(1)
    bool isIdenticalTree(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL and root2==NULL) return true;
        if(root1==NULL) return false;
        if(root2==NULL) return false;
        queue<TreeNode*> q1,q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty(),!q2.empty()){
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            if(node1->data!=node2->data)  return false;
            q1.pop();
            q2.pop();
            if(node1->left and node2->left){
                q1.push(node1->left);
                q2.push(node2->left);
            }
            else if(node1->left or node2->left) return false;
            if(node1->right and node2->right){
                q1.push(node1->right);
                q2.push(node2->right);
            }
            else if(node1->right or node2->right) return false;
        }
        return true;
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
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    bool ans  = isSameTree(root1,root2);
    cout<<ans<<endl;
    isIdenticalTree(root1,root2)?cout<<"Yes":cout<<"No";
}