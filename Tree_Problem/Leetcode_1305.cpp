
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



 void inOrderTraverse(TreeNode *root, vector<int>& vec)
    {
        if(root)
	    {
		    inOrderTraverse(root->left, vec);
		    vec.push_back(root->val);
		    inOrderTraverse(root->right, vec);

	    }
    }
	
    void mergeVectors(vector<int> vec1, vector<int> vec2, vector<int>& mergedVectors)
    {
        int i = 0, j = 0, k = 0; 

      
        while (i < vec1.size() && j < vec2.size()) 
        { 
        
            if (vec1[i] < vec2[j]) 
                mergedVectors[k++] = vec1[i++]; 
            else
                mergedVectors[k++] = vec2[j++]; 
        } 
  
    
        while (i < vec1.size()) 
            mergedVectors[k++] = vec1[i++]; 
  
    
        while (j < vec2.size()) 
            mergedVectors[k++] = vec2[j++]; 
        
        
    } 
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> tree1, tree2;
		
        inOrderTraverse(root1, tree1);
        inOrderTraverse(root2, tree2);
        
        vector<int> mergedVectors(tree1.size() + tree2.size());
		
        mergeVectors(tree1, tree2, mergedVectors);
        return  mergedVectors;
        
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