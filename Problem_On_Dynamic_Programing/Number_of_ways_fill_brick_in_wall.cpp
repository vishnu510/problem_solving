#include<bits/stdc++.h>
using namespace std;

// Using Dp bottom-up Approach
int WayOfFill(int n){
   int dp[n+1];
   dp[0]=dp[1]=dp[2]=dp[3] =1;
   for(int i=4;i<=n;i++){
       dp[i] = dp[i-1]+dp[i-4];
   }
   return dp[n];
}
// Solution with unneccessary space 
int Wayoffill_1(int n){
    if(n==0||n==1||n==2||n==3) return 1;
    else{
        return Wayoffill_1(n-1)+Wayoffill_1(n-4);
    }
}
int main(){

    int n =5;
    cout<<Wayoffill_1(n)<<endl;
    cout<<WayOfFill(n); 
    return 0;
}