//5. Longest Palindromic Substring
#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int n = s.size();
        int dp[n][n];
        memset(dp,-1,sizeof(dp)); 
        for (int i = 0; i < n; ++i) 
            dp[i][i] = 1;
        int maxLen = 1;
        int start = 0; 
        for (int i = 0; i < n - 1; ++i) { 
            if (s[i] == s[i + 1]) { 
                dp[i][i + 1] = 1; 
                start = i; 
                maxLen = 2; 
            } 
        }
        for(int k=3;k<=n;k++){ 
            for(int i=0;i<n - k + 1;i++){
                int j = i + k - 1;
                if(dp[i+1][j-1] == 1 && s[i] == s[j]){ 
                    dp[i][j] = 1;
                    if (k > maxLen) { 
                        start = i;
                        maxLen = k; 
                    } 
                }
            }
        }
        return s.substr(start, maxLen);
}

int main(){

    string str = "bb";
    cout<<longestPalindrome(str);
    return 0;
}