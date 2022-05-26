#include<bits/stdc++.h>
using namespace std;


int stringMatching(string s,string pattern){
    int len1 = s.size(),len2 = pattern.size();

    for(int i=0;i<=len1-len2;i++){
        int j;
        for(j=0;j<len1;j++){
            if(s[i+j]!=pattern[j]){
                break;
            }
        }
        if(j==len2){
            return i;
        }

    }
    
}

int main(){
    
    string str1 ="this is text-test",str2 = "text";
    cout<<"String Match at Index: ";
    cout<<stringMatching(str1,str2);
    return 0;
}