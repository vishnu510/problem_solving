#include<bits/stdc++.h>
using namespace std;

int main(){

    // this approach will take O(n^2) time 
    int nums[] = {2,6,4,8,10,9,15};
    int len = sizeof(nums)/sizeof(int);
    int start = len,end = 0;
    stack<int> s;
     
     // traverse the array from left to right
     s.push(0);
     for(int i=0;i<len;i++){
         if(nums[s.top()]<nums[i+1]){
             s.push(i+1);
         }
         else{
             start = min(start,i);
             s.pop();
         }
     }
     while(!s.empty()){
         s.pop();
     }

     s.push(len-1);
     for(int i=len-1;i>=0;i--){
         if(nums[s.top()]>nums[i-1]){
             s.push(i-1);
         }
         else{
             end = max(end,i);
             s.pop();
         }
     }
     while(!s.empty()){
         s.pop();
     }
     
     if(end-start>0){
         cout<<(end-start+1);
     }
     else{
         cout<<"0";
     }

    return 0;

}