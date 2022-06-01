//300. Longest Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;

  //Approach 1: Time Complexity = O(n^2)
int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int max_1 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i==0) dp[i] =1;
            else{
                for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                  dp[i] = max(dp[i],dp[j]+1);
                }
                else{
                    dp[i] = max(dp[i],1);
                }
            }
            }
            max_1 = max(max_1,dp[i]);
        }
        return max_1;
    }

    //Approach 2: Time Complexity = O(n * log(n))

int lengthOfLIS_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for(int i=0;i<n;i++){
            if(i==0) dp.push_back(nums[i]);
            else{
                auto num = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                if(num>=dp.size()){
                    dp.push_back(nums[i]);
                }
                else{
                    dp[num] = nums[i];
                }
            }
        }
        return dp.size();
    }
int main(){
    
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums)<<endl;
    cout<<lengthOfLIS_1(nums);
    return 0;
}