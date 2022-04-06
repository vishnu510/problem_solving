#include<bits/stdc++.h>
using namespace std;

int main(){

    // this approach take O(n) time and (n) space Wrong solution appropriate soltion is using XOR operation

    int nums[] = {9,6,4,2,3,5,7,0,1};
    int n = sizeof(nums)/sizeof(int);
    int m=n+2; 
    int sum  = m*(m+1)/2;
    for(int i=0;i<n;i++){
        sum-=nums[i];
    }
    int avg_sum = sum/2;
    int les_sum = 0;
    for(int i =0;i<n;i++){
        if(nums[i]<avg_sum){
            les_sum+=nums[i];
        }
    }
    int first_num = (les_sum-avg_sum);
    int sec_num = les_sum;
    cout<<first_num<<" "<<sec_num;
    return 0;
}