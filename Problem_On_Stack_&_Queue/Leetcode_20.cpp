// Valid parenthesis 
#include<bits/stdc++.h>
using namespace std;


bool isValidParan(string s){
    stack<char> st;
     int i;
    for(auto i:s){
        if(i=='(' || i=='{'||i=='['){
            st.push(i);
        }
        else{
            if(st.empty() || st.top()=='(' and i!=')'||st.top()=='{' and i!='}'||st.top()=='[' and i!=']'){
                return false;
            }
            st.pop();
        }
    }
        return st.empty();
}
int main(){
    
    string s = "()[]{}";
    bool res = isValidParan(s);
    cout<<res;
    
    return 0;
}