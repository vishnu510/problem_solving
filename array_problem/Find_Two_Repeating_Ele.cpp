#include<bits/stdc++.h>
using namespace std;

int main(){

    // 

    int nums[] = {2,4,3,1,2,5,4};
    int n = sizeof(nums)/sizeof(int);
    for(int i=0;i<n;i++){
       if(nums[abs(nums[i])]>=0){
          nums[abs(nums[i])] = -nums[abs(nums[i])];
       }
       else{
           cout<<abs(nums[i])<<" ";
       }

    }

    return 0;
}