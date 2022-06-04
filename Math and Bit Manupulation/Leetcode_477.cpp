//477. Total Hamming Distance
#include<bits/stdc++.h>
using namespace std;


// it will O(n*n) time
int findDistance(int n){
    int count = 0;
    while (n>0)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}
int totalHammingDistance(vector<int>& nums) {
    int res =0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            res+= findDistance(nums[i]^nums[j]);
        }
        
    }
    return res;
}
// second Approach
int totalHammingDis(vector<int> &nums){
    int result =0;
    for(int i=0;i<32;i++){
        int count=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j] & (1<<i)){
                count++;
            }
        }
        result+=(count*(nums.size()-count));
    }
    return result;
}
int main(){

    vector<int> nums = {4,14,2};
    cout<<totalHammingDistance(nums)<<endl;
    cout<<totalHammingDis(nums);
    return 0;
}