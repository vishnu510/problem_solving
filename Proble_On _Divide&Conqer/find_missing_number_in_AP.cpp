#include<bits/stdc++.h>
using namespace std;

int Missing_Number_in_Series(vector<int>& nums){
   int len = nums.size();
   int sum = ((len+1)/2*(nums[0]+len*(nums[1]-nums[0])));
   while(len--){
       sum-=nums[len];
   }
   return sum;
}

// Second Approach
int Missing_Number_in_Series_AP(vector<int>& nums){
   int diff = nums[1]-nums[0];
   for(int i=0;i<nums.size();i++){
       if(nums[i]!=(nums[0]+diff*i)){
           return (nums[0]+diff*i);
       }
   }
}
// binary search approach take O(logn) time


int Missing_Number_in_Series_1(vector<int>& nums,int min,int max,int diff){
    if(min>max) return 0;
      int mid = (min+max)/2;
      if(min==max){
          if(nums[min]!=nums[0]+diff*min){
              return nums[0] + diff*min;
          }
      }
      if(nums[mid]==nums[0] + diff*mid){
          mid = mid+1;
      }
      else{
          max = mid;
      }
      Missing_Number_in_Series_1(nums,min,max,diff);
}

int main(){
   vector<int> nums = {0,2,4,6,8,10,12,14,18,20,22};
   cout<<Missing_Number_in_Series(nums)<<"\n";
   cout<<Missing_Number_in_Series_AP(nums)<<"\n";
   cout<<Missing_Number_in_Series_1(nums,0,nums.size(),2);
  return 0;
}