#include<bits/stdc++.h>
using namespace std;

int main(){
     // this approach will take O(nlogn) time 
    vector<int> nums {3,5,2,1,6,4};
    int n  = nums.size();
    sort(nums.begin(),nums.end());
    for(int i=1;i<n-1;i = i+2){
            swap(nums[i],nums[i+1]);
    }
    for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
    }
    cout<<endl;
     // this approach will take O(n) time 
    vector<int> number {3,5,2,1,6,4};
    int num  = number.size();
   
    for(int i=1;i<n-1;i = i+2){
        if(i>0 and number[i]<number[i-1]){
            swap(number[i],number[i-1]);
        }
        if(i<num-1 and number[i]<number[i+1]){
            swap(number[i],number[i+1]);
        }
    }
            
    for(int i=0;i<n;i++){
            cout<<number[i]<<" ";
    }
    

    return 0;
}