//338. Counting Bits;
#include<bits/stdc++.h>
using namespace std;
//it will take O(nk) time space O(1)
vector<int> countBits(int n) {
    vector<int> ans;
    int num;
    for(int i=0;i<=n;i++){
        num=i;
        int count =0;
        while(num>0){
            
            if(num%2==1){
                count++;
            }
            num=num>>1;
        }
        ans.push_back(count);
    }
    return ans;
}
// Next Approach it will take O(n) time
vector<int> countBit(int n){
    vector<int> dp(n+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i/2] + i%2;
    }
    
    return dp;
}
// Next Approach it will reduce the itration
vector<int> countBit_1(int n){
    vector<int> dp(n+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i&(i-1)] + 1;
    }
    
    return dp;
}
int main(){

    vector<int> ans = countBits(2);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> res = countBit(2);
    for(auto i:res){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> result = countBit_1(2);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}