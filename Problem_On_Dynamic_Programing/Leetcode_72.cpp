//72. Edit Distance
#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        for(int i=0;i<word1.length()+1;i++){
            for(int j=0;j<word2.length()+1;j++){
                if(i==0){
                    dp[i][j] = j;
                }
                else if(j==0){
                    dp[i][j] =i;
                }
                else{
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        int add = dp[i][j-1];
                        int replace = dp[i-1][j-1];
                        int remove = dp[i-1][j];
                        dp[i][j] = 1+min(min(replace,remove),add);
                    }
                    
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }

int main(){
    
    string s1 = "horse",s2="ros";
    cout<<minDistance(s1,s2);
    return 0;
}