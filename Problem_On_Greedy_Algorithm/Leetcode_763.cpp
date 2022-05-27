#include<bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
        int len = s.size();
        if(len==0) return {};
        vector<int> LastInx(26,0);
        for(int i=0;i<len;i++){
            LastInx[s[i]-'a'] = i;
        }
        vector<int> res;
        int start=0,end=0;
        for(int i=0;i<len;i++){
            end = max(end,LastInx[s[i]-'a']);
            if(i==end){
                res.push_back(i-start+1);
                start = i+1;
            }
        }
        return res;
    }

int main(){
    
    string str = "ababcbacadefegdehijhklij";
    vector<int> ans = partitionLabels(str);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}