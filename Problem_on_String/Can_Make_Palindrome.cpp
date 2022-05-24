#include<bits/stdc++.h>
using namespace std;

bool arrangePalindrome(string s){
    int len = s.length();
    unordered_map<char,int> count;
    for(int i=0;i<len;i++){
        count[s[i]]++;
    }
    int oddCount = 0;
    for(int i=0;i<len;i++){
      if(count[s[i]]%2==1){
          oddCount++;
      }
      else{
          oddCount--;
      }
    }
    if(oddCount>1) return false;
    else return true;
}

int main(){
    string str = "carrace";
    cout<<arrangePalindrome(str);

    return 0;
}