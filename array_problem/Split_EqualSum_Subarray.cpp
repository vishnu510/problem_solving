#include<iostream>
using namespace std;

bool SplitSumEqual(int arr[],int n){
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int left_sum = sum;
    int right_sum = 0;
    for(int i=n-1;i>0;i--){
        right_sum+=arr[i];
        left_sum-=arr[i];
        if(right_sum==left_sum){
            return true;
        }
    }
    return false;
}


int main(){
     
     // Naive solution O(n^2) time 
    int arr[] = {1,2,3,4,5,5};
    int size  = sizeof(arr)/sizeof(int);
    int left_sum = 0;
    for(int i=0;i<size;i++){
        left_sum+=arr[i];
        int right_sum =0;
        for(int j =i+1;j<size;j++){
            right_sum+=arr[j];
        }
        if(right_sum==left_sum){
            cout<<i;
        }
        
    }
    cout<<endl;
    // lets's try for better
     int arr1[] = {1,2,3,5};
    int size1  = sizeof(arr)/sizeof(int);
    bool ans =  SplitSumEqual(arr1,size1);
    cout<<ans;


    return 0;
}