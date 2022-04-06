#include<bits/stdc++.h>
using namespace std;


bool findTriplet(int nums[],int len){
    
    if(len<3) return false;

    int left = INT_MAX;
    int mid = INT_MAX;

    for(int i =0;i<len;i++){
        if(nums[i]>mid){
            return true;
        }
        else if(nums[i]>left && nums[i]<mid){
            mid  = nums[i];
        }
        else if(nums[i]<left){
            left = nums[i];
        }
    }
    return false;
}



int main(){
    
     int arr[] = {2,1,5,0,4,6};
     //brute force approach for finding increasing triplet present or not it will O(n^2) time\

      int low ,high,mid;
      int len = sizeof(arr)/sizeof(int);
      low = 0;
      high = len -1;
      mid  = (high-low)/2;
      bool flag = false;
      for(int i = 0;i<len;i++){

          for (int j=0;j<=mid-1;j++){
                   if(arr[j]<arr[mid]){
                     flag =true;
                   }   
                   else{
                       flag = false;
                   }     
          }
          for (int j=high-1;j>mid;j--){
                   if(arr[j]>arr[mid++]){
                     flag =true;
                   }   
                   else{
                       flag = false;
                   }     
          }
      }
      cout<<flag;

      cout<<endl;

      // let's try for something better O(n) time 

      int array[] = {2,1,5,0,4,6};
      int n = sizeof(arr)/sizeof(int);
     bool ans = findTriplet(array,n);
     cout<<ans;

    return 0;
}