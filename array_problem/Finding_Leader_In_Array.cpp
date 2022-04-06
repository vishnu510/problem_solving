#include<bits/stdc++.h>
using namespace std;

int main(){

    // It's brute force approach taking o(n^2) time complexity
    int arr[] = {10,6,3,1,7,9};
    int len = sizeof(arr)/sizeof(int);
    for(int i=0;i<len;i++){
        int maxi=0;
        for (int  j = i+1; j < len; j++)
        {
            maxi = max(maxi,arr[j]);
        }
        if(arr[i]>maxi){
            cout<<arr[i]<<" ";
        }
    }
   
     cout<<endl;

    // let's try for something better  O(n) T.C.
      int arr1[] = {8,4,2,3,1,5,4,2};
    int len1 = sizeof(arr1)/sizeof(int);
    int maxi = 0;
    //traversing from right to left
    for(int i=len1-1;i>=0;i--){
        if(arr1[i]>maxi){
            cout<<arr1[i]<<" ";
            maxi = max(maxi,arr1[i]);
            
        }
    }
   
    return 0;
}