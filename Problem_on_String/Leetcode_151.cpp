//151. Reverse Words in a String
#include<bits/stdc++.h>
using namespace std;
stack<char> ans;
string reverseWords(string s) {
    stringstream str(s);
    string ans = "";
    string word;
    vector<string> vec;
    while(str>>word){
         vec.push_back(word);
    }
     reverse(vec.begin(),vec.end());
     for(auto i:vec){
         if(ans.size()) ans+= ' ';
         ans+=i;
     }
     return ans;
    }
    // Using Stack 
    string reverseWords_1(string s) {
        if(s.size()==0) return s;
        stack<string> stk;
        string result;
        for(int i=0;i<s.size();i++){
            string word;
            if(s[i]==' ') continue;
            while (i<s.size() and s[i]!=' ')
            {
                word+=s[i];
                i++;
            }
           stk.push(word);    
        }
       while (!stk.empty())
       {
           result+=stk.top();
           stk.pop();
           if(!stk.empty()) result+=' ';
       }
       return result;
    }

int main(){
    
    string str = "the sky is blue";
    string ans = reverseWords(str);
    cout<<ans<<endl;
    ans = reverseWords_1(str);
    cout<<ans;
    return 0;
}