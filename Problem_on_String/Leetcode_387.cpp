//387. First Unique Character in a String
#include<bits/stdc++.h>
using namespace std;


int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
                mp[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]==1) return i;
        }
        return -1;
         
    }

    // Second Approach
    int firstUniqChar_1(string s) {
        vector<int> vec(26,0);
        for(auto i:s){
            vec[i-'a']++;
        }
        for(int ans=0;ans<s.length();ans++){
            if(vec[s[ans]-'a']==1) return ans;
        }
        return -1; 
    }

int main(){
    
    string str = "leetcode";
    cout<<firstUniqChar(str)<<"\n";
    cout<<firstUniqChar_1(str);
    return 0;
}