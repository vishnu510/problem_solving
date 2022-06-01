//72. Edit Distance
#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
        int x = word1.size(),y = word2.size();
        int dp[x+1][y+1];
        for(int i=0;i<x;i++){
            dp[0][i] =i;
        }
         for(int i=0;i<y;i++){
            dp[i][0] =i;
        }
        for(int i=1;i<x;i++){
            for(int j=1;j<y;j++){
                if(word1[j-1]==word2[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] =min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]));
                }
            }
        }
        return dp[x-1][y-1];
    }

int main(){
    
    string s1 = "horse",s2="ros";
    cout<<minDistance(s1,s2);
    return 0;
}