//703. Kth Largest Element in a Stream
#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
   priority_queue<int,vector<int>,greater<int>> minheap;
   int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(auto x:nums) add(x);
        
    }
    
    int add(int val) {
        if(minheap.size()<size) minheap.push(val);
        else{
            if(val>minheap.top()){
               minheap.pop();
               minheap.push(val);
            }
        }
    }
};

int main(){

    return 0;
}