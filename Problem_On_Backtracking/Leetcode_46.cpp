//46 Permuntations
#include<bits/stdc++.h>
using namespace std;

void permutation(vector<int>& nums,vector<vector<int>>& res,int l){
    if(l>=nums.size()){
        res.push_back(nums);
        return;
    }
    else{
        for(int i=l;i<nums.size();i++){
            swap(nums[l],nums[i]);
            permutation(nums,res,l+1);
            swap(nums[l],nums[i]);
        }
    }

}

vector<vector<int>> permute(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> res;
    permutation(nums,res,0);
    return res;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    cout<<"[";
    for(int i=0;i<res.size();i++){
        cout<<"[";
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<",";
        }
        cout<<"]";
    }
    cout<<"]";
    return 0;
}