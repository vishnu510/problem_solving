#include<bits/stdc++.h>
using namespace std;

int MaxSumSubarray(vector<int>& nums){
    int MaxSum = INT_MIN,sum=0;
    for(int i=0;i<nums.size();i++){
        sum+= nums[i];
        if(nums[i]>sum){
            sum = nums[i];
        }
        MaxSum = max(sum,MaxSum);
    }
    return MaxSum;
}
// Iterative bottom-up Approach 
int MaxSumSubarray_1(vector<int>& nums){
    int max_sum = nums[0];
    int curr_max = nums[0];
    for(int i=0;i<nums.size();i++){
        curr_max = max(nums[i],curr_max+nums[i]);
        if(max_sum<curr_max) max_sum = curr_max;
    }
    return max_sum;
}

int main(){
    
    vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    cout<<MaxSumSubarray(nums)<<"\n";
    cout<<MaxSumSubarray_1(nums);
    return 0;
}