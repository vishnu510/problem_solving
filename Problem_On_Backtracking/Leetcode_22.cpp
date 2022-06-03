//22. Generate Parentheses
#include<bits/stdc++.h>
using namespace std;

void solution(int open,int close,string output,vector<string>& res){
    if(open == 0 && close == 0){
            res.push_back(output);
            return;
        }
        if(open != 0){
            string openOutput = output + "(";
            solution(open-1, close, openOutput, res);    
        }
        if(close > open){
            string closeOutput = output + ")";
            solution(open, close-1, closeOutput, res);
        }
}

vector<string> generateParenthesis(int n){
    vector<string> res;
    int open =n,close=n;
    string output = "";
    solution(open,close,output,res);
    return res;
}

int main(){
    vector<string> ans = generateParenthesis(3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
    return 0;
}