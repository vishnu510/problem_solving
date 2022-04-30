// Spiral order traversal
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
 
};
TreeNode* newNode(int data){
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     stack<TreeNode*> LtoR, RtoL;
        int level = 1;
        
        vector<vector<int>> ans;
        
        if(!root) return ans;

        RtoL.push(root);

        while(!RtoL.empty() || !LtoR.empty()) {
            
            vector<int> v;
            
            if(level % 2 == 1) {
                                
                while(!RtoL.empty()) {

                    TreeNode* curr = RtoL.top();
                    RtoL.pop();
                    v.push_back(curr -> val);

                    if(curr -> left) LtoR.push(curr -> left);
                    if(curr -> right) LtoR.push(curr -> right);        
                }   

            } else {
                
                while(!LtoR.empty()) {

                    TreeNode *curr = LtoR.top();
                    LtoR.pop();
                    v.push_back(curr -> val);

                    if(curr -> right) RtoL.push(curr -> right);
                    if(curr -> left) RtoL.push(curr -> left);                
                } 
            }
            
            ans.push_back(v);
            level++;
            
        }
        
        return ans;

    }
int main(){
    TreeNode*root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->left = newNode(70); 
    root->left->right = newNode(60); 
    root->right->left = newNode(50); 
    root->right->right = newNode(40); 
    vector<vector<int>> res = zigzagLevelOrder(root);
    cout<<"[";
    for (int i = 0; i < res.size(); i++) {
        cout<<"[";
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "]"<<",";
    }
     cout << "]";
    return 0;
}