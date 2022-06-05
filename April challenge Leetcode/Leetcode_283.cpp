//283. Move Zeroes
#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeroes(vector<int>& nums) {
    if(nums.size()<2) return nums;
    int countZero = 0;
    int index=0;
    
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[index]=nums[i];
            index++;
        }
        else{
            countZero++;
        }
    }
        while (countZero--)
    {
        nums[index] = 0;
        index++;
    }
    
    return nums;
}

int main(){

    vector<int> nums = {0,1,0,3,12};
    vector<int> ans = moveZeroes(nums);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}