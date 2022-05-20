//Vertical Order Traversal of a Binary Tree
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* builtTree(int val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

void vertical_traversal(TreeNode *root, int distance, int level, map<int, set<pair<int,int>>>&mp){
    if(root==NULL) return;
    mp[distance].insert({level,root->val});
    vertical_traversal(root->left,distance-1,level+1,mp);
    vertical_traversal(root->right,distance+1,level+1,mp);
}
 vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,set<pair<int,int>>> mp;
        vertical_traversal(root,0,0,mp);
        vector<vector<int>> result;
        for(auto it:mp){
            vector<int> temp;
            for(auto i:it.second){
                temp.push_back(i.second);
            }
            result.push_back(temp);
        }
        return result;
    }

int main(){

    TreeNode* root = builtTree(3);
    root->left = builtTree(9);
    root->right = builtTree(20);
    root->right->left = builtTree(15);
    root->right->right = builtTree(7);

    vector<vector<int>> answer = verticalTraversal(root);\
    cout<<"[";
     for (int i = 0; i < answer.size(); i++) {
         cout<<"[";
        for (int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j] << " ";
            cout<<"]";
            cout<<",";
    }
    cout<<"]";
    return 0;
}