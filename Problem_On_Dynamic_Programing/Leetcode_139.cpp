//139. Word Break
#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
               if((dp[j]) && (find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end())){
                   dp[i] = true;
                   break;
               }
            }
        }
        return dp.back();
    }

int main(){
     string str = "leetcode";
     vector<string> wordDict = {"leet","code"};
     cout<<wordBreak(str,wordDict);
    return 0;
}