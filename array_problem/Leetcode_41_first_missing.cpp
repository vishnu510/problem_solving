#include<bits/stdc++.h>
using namespace std;

int main(){
   
     // this approach will take O(nlogn) time 
    int nums[] = {3,4,-1,1};
    int n = sizeof(nums)/sizeof(int);
    int result= 1;
    sort(nums,nums+n);
    for(int i=0;i<n;i++){
        if(nums[i]==result){
            result+=1;
            
        }
    }
    cout<<result<<endl;


    return 0;
}