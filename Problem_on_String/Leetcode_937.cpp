//937. Reorder Data in Log Files
#include<bits/stdc++.h>
using namespace std;

static bool compare(string s1,string s2){
        string aa = s1.substr(s1.find(' '));
        string bb = s2.substr(s2.find(' '));
       
        return aa == bb ? s1 < s2 : aa < bb;
    }
	
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> result;
        int count = 0;
        
        for(auto log : logs){
            if(log.back() <= 'z' and log.back() >= 'a') result.insert(result.begin(),log),count++;
            else result.push_back(log);
        }
        sort(result.begin(),result.begin()+count,compare);
        return result;  
    }

int main(){
    vector<string> logs ={"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> ans = reorderLogFiles(logs);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}