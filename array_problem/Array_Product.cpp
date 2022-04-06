#include<bits/stdc++.h>
using namespace std;

int main(){

    // Approach :1 left and right product O(n) t.c. and O(n) s.c.
                
        int nums[] = {-1,1,0,-3,3};
        int n = sizeof(nums)/sizeof(int);
        int left=1;
        int L[n],R[n];

       L[0] = left;
        for(int i=0;i<n;i++){
            left = left*nums[i];
            L[i+1] = left;
        }
        R[n-1] = 1;
        int right =1;
        for(int i=n-1;i>0;i--){
            right = right*nums[i];
            R[i-1] = right;
        }
        for(int i=0;i<n;i++){
            nums[i] = L[i]*R[i];
        }
         for(int i=0;i<n;i++){
            cout<<nums[i]<<",";
        }

        //Approch 2 O(n) time and (1) space because output array don't count as a extra space
        cout<<endl;

        int arr[] = {-1,1,0,-3,3};
        int size = sizeof(arr)/sizeof(int);
        int output[n];
        output[0] =1;
        for(int i=1;i<n;i++){
            output[i] = arr[i-1]*output[i-1];
        }
        int r =1;
        for(int i=n-1;i>=0;i--){
            output[i] = output[i]*r;
            r = r*arr[i];
        }
        for(int i=0;i<n;i++){
            cout<<output[i]<<",";
        }


    return 0;
}