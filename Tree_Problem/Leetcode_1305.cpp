
// Problem Number :1305. All Elements in Two Binary Search Trees
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

vector<int> results;
void elements(TreeNode* root){
        if(!root) return;
        results.push_back(root->val);
        elements(root->left);
        elements(root->right);
    }
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(!(root1 || root2)) return {};
        elements(root1);
        elements(root2);
        sort(results.begin(),results.end());
        return results;
    }

int main(){
    TreeNode* root1 = builtTree(2);
    root1->left = builtTree(1);
    root1->right = builtTree(4);
    TreeNode* root2 = builtTree(1);
    root2->left = builtTree(0);
    root2->right = builtTree(3);
    
    vector<int> result = getAllElements(root1,root2);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}