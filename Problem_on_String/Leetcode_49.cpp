//49. Group Anagrams
#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        int i=0,len = strs.size();
        while(i<len){
            string str = strs[i];
            sort(str.begin(),str.end());
            map[str].push_back(strs[i]);
            i++;
        }
       for(auto i=map.begin();i!=map.end();i++){
           result.push_back(i->second);
       }
       
       return result;
    }

int main(){
    
    vector<string> strs= {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans  = groupAnagrams(strs);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";
    return 0;
}