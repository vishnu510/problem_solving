//318. Maximum Product of Word Lengths
#include<bits/stdc++.h>
using namespace std;
// Brute force  take O(n^2)*k time
bool noCommonChar(string s1,string s2){
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(s1[i]==s2[j]){
                return false;
            }
        }
    }
    return true;
}
int maxProduct(vector<string>& words) {
    int n = words.size(),maxVal=0,len1,len2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(noCommonChar(words[i],words[j])){
                len1 = words[i].size();
                len2=words[j].size();
                maxVal = max(maxVal,len1*len2);
            }
        }
    }
    return maxVal;
}
// this will take o(n*n)

int maxProducts(vector<string>& words) {
    vector<int> v;
        for(string &ss:words)
        {
            int mask = 0;
            for(char &ch:ss)
            {
                mask |= (1<<(ch-'a'));
            }
            v.push_back(mask);    
        }
        int ans=0;
        
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = i+1; j < v.size(); j++)
            {
                if((v[i] & v[j])==0)
                {
                    ans= max(ans, (int)(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
}
int main(){
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout<<maxProduct(words)<<endl;
    cout<<maxProducts(words);
    return 0;
}