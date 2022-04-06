#include<bits/stdc++.h>
using namespace std;

int main(){
     
     int nums[] = {2,0,2,1,1,0};
     int len = sizeof(nums)/sizeof(int);
     int curr = 0,low = 0,high =len-1;

     while(curr < high){

         if(nums[curr]==0){
             
        swap(nums[curr],nums[low]);
        curr++;
        low++;

         }

         if(nums[curr] == 1){

              curr++;

         }
         if(nums[curr]==2){
             swap(nums[curr],nums[high]);
             high--;
         }
     }

     for( int c=0;c<len;c++){
        cout<<nums[c]<<",";
     }

     cout<<endl;
     // Other Approach O(n) T.C.

     int nums1[] = {2,0,2,1,1,0};
     int len1 = sizeof(nums1)/sizeof(int);
      int l = 0, mid = 0, h = len1 - 1;
        
        
        while(mid <= h)
        {
            switch(nums1[mid])
            {
                case 0: swap(nums1[l++], nums1[mid++]); break;
                
                case 1: mid++; break;
                
                case 2: swap(nums1[mid], nums1[h--]); break;
            }
        }

        
     for( int c=0;c<len1;c++){
        cout<<nums1[c]<<",";
     }

    return 0;
}