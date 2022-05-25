//91. Decode Ways
#include<bits/stdc++.h>
using namespace std;


int numDecodings(string s) {
        int len = s.size();
        if(len==1) return 1;
        if(s[0]=='0') return 0;
        vector<int> result(len+1,0);
        result[0]=1;
        result[1] = 1;
        for(int i=2;i<=len;i++){
            int oneDigit = s[i-1]-'0';
            int twoDigit = (s[i-2]-'0')*10 + (s[i-1]-'0');
            if(oneDigit>=1){
                result[i]+= result[i-1];
            }
            if(twoDigit>=10 and twoDigit<=26){
                result[i]+=result[i-2]; 
            }
        }
        return result[len];
            }

// Second Approach
 
int getDecoding(string s,int pos){
    if(pos==s.size()) return 1;
    if(s[pos]=='0') return 0;
    if(pos == s.size()-1) return 1;
    string sub = s.substr(pos,2);
    int type_1 = getDecoding(s,pos+1);
    int type_2 =0;
    if(stoi(sub)<=26 and stoi(sub)>0){
        type_2 = getDecoding(s,pos+2);
    }
    return (type_1+type_2);
}

int numDecodings_1(string s) {
        int ans = 0;
        ans = getDecoding(s,0);
        return ans;
            
 }            

int main(){
    
    string str = "12";
    cout<< numDecodings(str)<<endl;
    cout<< numDecodings_1(str);
    return 0;
}