#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        s+=s;
        if(s.find(goal)!=string::npos) return true;
        return false;
    }

int main(){

    string str="abcde",goal ="cdeab";
    cout<<rotateString(str,goal);
    return 0;
}