// 516. Longest Palindromic Subsequence
#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
        int len  = s.size();
        string word = s;
        reverse(s.begin(),s.end());
        int dpMat[len+1][len+1];
        for(int i = 0;i<len+1;i++){
           dpMat[i][0] =0;
        }
         for(int i = 0;i<len+1;i++){
           dpMat[0][i] =0;
        }
        for(int i =1;i<=len;i++){
           for(int j=1;j<=len;j++){
               if(s[i-1]==word[j-1]){
                 dpMat[i][j] = 1 + dpMat[i-1][j-1];
               }
               else{
                   dpMat[i][j] = max(dpMat[i][j-1],dpMat[i-1][j]);
               }
           }
        }
        return dpMat[len][len];
    }

    // recursive Approach
    int longestCommonSubsequence(string s,string str,int m,int n){
          if(m==0 || n==0){
              return 0;
          }
          if(s[m-1]==str[n-1]){
              return 1 + longestCommonSubsequence(s,str,m-1,n-1);
          }
          else{
              return max(longestCommonSubsequence(s,str,m-1,n),longestCommonSubsequence(s,str,m,n-1));
          }
    }
    int longestPalindromeSubseq_1(string s) {
       int len = s.length();
       string str = s;
       reverse(s.begin(),s.end());
       return longestCommonSubsequence(s,str,len,len);
    }

int main(){
    string str = "bbbab";
    cout<<longestPalindromeSubseq(str)<<endl;
    cout<<longestPalindromeSubseq_1(str);
    return 0;
}