//567. Permutation in String
#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    unordered_map<char,int> s1Map;
    for(auto it:s1){
        s1Map[it]++;
    }
    int windowSize = s1.size();
    int windowEnd = 0,matched =0;
    for(int windStart =0;windStart<s2.size();windStart++){
        auto it = s1Map.find(s2[windStart]);
        if(it!=s1Map.end()){
            s1Map[it->first]--;
            if(s1Map[it->first]==0){
                matched++;
            }
        }
        if(matched==s1.size()){
            return true;
        }
        if(s1.size()<=windStart+1-windowEnd){
            auto iter = s1Map.find(s2[windowEnd]);
            if(iter!=s1Map.end()){
                if(s1Map[iter->first]==0){
                    matched--;
                }
                s1Map[iter->first]++;
            }
            windowEnd++;
        }
    }
    return false;
}

int main(){

    string str1 = "ab",str2="eidbaooo";
    cout<<checkInclusion(str1,str2);

    return 0;
}