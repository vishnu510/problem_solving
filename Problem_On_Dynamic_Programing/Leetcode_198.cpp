//198. House Robber
#include<bits/stdc++.h>
using namespace std;

//Dynamic Programming
//Time Complexity : O(n)
//Space Complexity : O(n)
int rob(vector<int>& nums) {
    
       int n= nums.size();
       if(n==1) return nums[0];
       int dp[n];
       dp[0]=nums[0];
       dp[1] =max(nums[0],nums[1]);
       for(int i=2;i<n;i++){
           dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
       }
       return dp[n-1];
}
// Second Approach Time Complexity : O(n)
//Space complexity : O(1)
int robs(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    int pre_sum2 = nums[0],prev_sum = max(nums[0],nums[1]),curr_sum = prev_sum;
    for(int i=2;i<n;i++){
        curr_sum = max(prev_sum,pre_sum2+nums[i]);
        pre_sum2 = prev_sum;
        prev_sum = curr_sum;
    }
    return curr_sum;
}
int main(){
     
     vector<int> nums = {1,2,3,1};
     cout<<rob(nums)<<endl;
     cout<<robs(nums);
     return 0;
}