#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            minheap.push({i->second,i->first});
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        vector<int> result;
        while (minheap.size()>0)
        {
            result.push_back(minheap.top().second);
            minheap.pop();
        }
        return result;
    }

int main(){

    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans = topKFrequent(nums,2);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}