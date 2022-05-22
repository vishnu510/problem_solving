#include<bits/stdc++.h>
using namespace std;
      static bool comparator(pair<string,int> p1,pair<string,int> p2){
        if(p1.second>p2.second ||(p1.second==p2.second && p1.first<p2.first)) return true;
        return false;
      }
 vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for(int i=0;i<words.size();i++){
            map[words[i]]++;
        }
        vector<pair<string,int>> vec;
        for(auto i = map.begin();i!=map.end();i++){
            vec.push_back({i->first,i->second});
        }
        sort(vec.begin(),vec.end(),comparator);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
int main(){
    
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    vector<string> ans = topKFrequent(words,2);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}