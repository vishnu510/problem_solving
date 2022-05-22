//215. Kth Largest Element in an Array

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(),nums.end());
        for(int i=0;i<k-1;i++){
            q.pop();
        }
        return q.top();
    }

int main(){
    vector<int> nums{3,2,1,5,6,4};
    cout<<findKthLargest(nums,2);
    return 0;
}