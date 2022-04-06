#include<bits/stdc++.h>
using namespace std;

int main(){

    // this approach will take O(n^2) time 
    int nums[] = {2,6,4,8,10,9,15};
    int len = sizeof(nums)/sizeof(int);
    int start = len,end = 0;
        
        for(int i=0; i<len-1; i++){
            
            for(int j = i+1; j<len; j++){
                if(nums[i]>nums[j]){
                    start = min(start,i);
                    end = max(end,j);
                }
            }
        }
        if(end-1<0){
            cout<<"0";
        }
        else{
            cout<<(end-start+1);
        }
     

       cout<<endl;
        // title optimal approach it will take O(nlogn) time and SC = O(n)
        
        int nums1[] = {2,6,4,8,10,9,15};
   
        sort(nums1,nums1+len);
        for(int i=0; i<len; i++){
            
                if(nums[i]!=nums1[i]){
                    start = min(start,i);
                    end = max(end,i);
                }
        }
        if(end-start>=0){
            cout<<(end-start+1);
        }
        else{
            cout<<"0";
        }

    
    return 0;
}