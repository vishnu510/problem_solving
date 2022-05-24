//438. Find All Anagrams in a Strin#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p) {
        int ls = s.length(),lp=p.length();
        if(lp>ls) return {};
        vector<int> vecs(26,0),vecp(26,0),res;
        for(int i=0;i<lp;i++){
            vecp[p[i]-'a']++;
        }
        int i=0,j=0;
        while(j<ls){
            vecs[s[j]-'a']++;
            if((j-i+1)<lp){
                j++;
            }
            else if((j-i+1)==lp){
                if(vecs==vecp){
                   res.push_back(i);
                }
                
                vecs[s[i]-'a']--;
                i++;
                j++;
            }
            
        }
        return res;
    }
int main(){
    
    string str1 = "cbaebabacd",str2 = "abc";
    vector<int> ans= findAnagrams(str1,str2);
    cout<<"[";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"]";
    return 0;
}