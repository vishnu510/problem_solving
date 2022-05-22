
// Problem Number :117. Populating Next Right Pointers in Each Node II
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
  Node *left;
  Node *right;
  Node *next;

};
Node* builtTree(int val){
    Node* temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q ;
        q.push(root);
        while(!q.empty()){
            int n =q.size();
            while(n--){
                Node* curr = q.front();
                q.pop();
                if(n==0) curr->next = NULL;
                else curr->next = q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return root;
    }

    
void printTree(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);

}

int main(){
    Node* root = builtTree(1);
    root->left = builtTree(2);
    root->right = builtTree(3);
    root->left->left =builtTree(4);
    root->left->right =builtTree(5);
    root->right->right = builtTree(7);
    connect(root);
    printTree(root);
    return 0;
}