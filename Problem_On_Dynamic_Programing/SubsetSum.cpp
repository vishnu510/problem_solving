#include<bits/stdc++.h>
using namespace std;

bool SubsetSumIndex(vector<int>& nums,int num){
       int n = nums.size();
       bool dp[n+1][num+1];
       for(int i=0;i<=n;i++){
           dp[i][0] = true;
       }
       
       for(int i=0;i<=num;i++){
           dp[0][i] = true;
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=num;j++){
               if(j<nums[i-1]){
                   dp[i][j] = dp[i-1][j];
               }
               if(j>=nums[i-1]){
                   dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
               }
           }
       }
       return dp[n][num];
}

int main(){

    vector<int> nums = {2,4,3,5};
    cout<<SubsetSumIndex(nums,6);
    return 0;
}