// Level order tree Traversal

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
vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        TreeNode* temp;
        int len;
        while(!q.empty()){
          len = q.size();
          vector<int> vec;
          for(int i=0;i<len;i++){
             temp = q.front();
             q.pop();
             vec.push_back(temp->data);
             if(temp->left) q.push(temp->left);
             if(temp->right) q.push(temp->right);
          }
          ans.push_back(vec);
        }
        return ans;
    }
int main(){
    TreeNode*root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    vector<vector<int>> res = levelOrder(root);
    cout<<"[";
    for (int i = 0; i < res.size(); i++) {
        cout<<"[";
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "]"<<",";
    }
     cout << "]";
}