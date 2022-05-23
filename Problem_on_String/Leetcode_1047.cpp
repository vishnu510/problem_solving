//1047. Remove All Adjacent Duplicates In String
#include<bits/stdc++.h>
using namespace std;


// best approach time O(n) and space O(1)
string removeDuplicates(string s) {
        int slow=0;
        for(int fast=1;fast<s.length();fast++){
            if(slow<0 || s[slow]!=s[fast]){
                s[++slow] = s[fast];
            }
            else{
                --slow;
            }
        }
        return s.substr(0,slow+1);
    }

    // using stack
string removeDuplicates_1(string s) {
        stack<char> res;
        string ans;
        for(int i=0;i<s.length();i++){
            if(res.size()==0) res.push(s[i]);
            else if(s[i]==res.top()) res.pop();
            else res.push(s[i]);
        }
        while (!res.empty())
        {
            ans+=res.top();
            res.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

int main(){
    
    string str = "abbaca";
    string ans = removeDuplicates(str);
    cout<<ans<<endl;
    ans = removeDuplicates_1(str);
    cout<<ans;
    return 0;
}