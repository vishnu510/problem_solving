#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {11,15,26,38,9,10};
    int len = sizeof(arr)/sizeof(int);
    int left = 0,right = 0;
    int sum = 35;
    int i;
    for(i=0;i<len-1;i++){
        if(arr[i]>arr[i+1]){
            break;
        }
    }
    left = (i+1)%len;
    right = i;
    while(left!=right){
       if(arr[left] + arr[right] == sum){
           cout<<"true";
       }

       if(arr[left] + arr[right] < sum){
           left = (left + 1)%len;
       }
       else{
           right = (len + right - 1)% len;
       }
    }
    return 0;
}