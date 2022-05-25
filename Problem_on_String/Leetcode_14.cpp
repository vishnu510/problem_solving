//14. Longest Common Prefix
#include<bits/stdc++.h>
using namespace std;


int findMinLen(vector<string>& strs){
    int min = strs[0].size();
    for(int i=1;i<strs.size();i++){
        if(min>strs[i].size()){
            min = strs[i].size();
        }
    }
    return min;
}

string longestCommonPrefix(vector<string>& strs) {
      if(strs.size()==0) return "";
      int minlen = findMinLen(strs);
      string res = "";
      for(int i=0;i<minlen;i++){
          char curr = strs[0][i];
          for(int j=0;j<strs.size();j++){
              if(strs[j][i]!=curr){
                   return res;
              }
          }
          res+=curr;
      }
     return res;
    }
    // Second Approach
    string longestCommonPrefix_1(vector<string>& strs) {
      if(strs.size()==0) return "";
      int len = strs.size();
      sort(strs.begin(),strs.end());
      string str1 = strs[0];
      string str2 = strs[len-1];
      string result;
      for(int i=0;i<len;i++){
          if(str1[i]==str2[i]){
              result+=str1[i];
          }
          else break;
      }
      return result;

    }

int main(){
    
     vector<string>str = {"flower","flow","flight"};
    cout<<longestCommonPrefix(str);
    cout<<longestCommonPrefix_1(str);
    
    return 0;
}