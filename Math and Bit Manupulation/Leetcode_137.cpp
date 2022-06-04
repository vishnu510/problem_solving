//137. Single Number II
#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    for(auto i=map.begin();i!=map.end();i++){
        if(i->second==1){
            return i->first;
        }
    }
    return 0;
}
// Second Approach constant Space
int singleNumbers(vector<int>& nums){
    int one=0,two=0;
    int nonThree;
    for(int i=0;i<nums.size();i++){
        two |=one & i;
        one^= i;
        nonThree= ~(one&two);
        one&= nonThree;
        two&= nonThree;
    }
    return one;
}

int main(){

    vector<int> nums = {2,2,3,2};
    cout<<singleNumber(nums)<<endl;
    cout<<singleNumbers(nums);
    return 0;
}