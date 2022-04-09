#include<bits/stdc++.h>
using namespace std;

// this will take O(n) time 
int find_peak_ele(vector<int> nums,int n){

    for(int i=0;i<n;i++){
        if(nums[i]>nums[i+1]){
            return i;
        }
    }
    return (n-1);
}

// this Approach will take O(logn) time 
int find_peak_ele_1(vector<int> nums,int n){
    int low =0,high =n-1;
       while(low<high){
           int mid = low +(high-low)/2;
           if(nums[mid]<nums[mid+1]){
               low = mid+1;
           }
           else{
               high= mid;
           }
       }
       return low;
}

int main(){

   vector<int> nums{1,2,3,4,5};

   int n = nums.size();
   cout<<find_peak_ele(nums,n)<<endl;
  
   vector<int> number{1,2,3,4,5};
   int num = nums.size();
   cout<<find_peak_ele_1(number,num)<<endl;

    return 0;
}