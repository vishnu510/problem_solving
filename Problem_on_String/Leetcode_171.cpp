#include<bits/stdc++.h>
using namespace std;


int titleToNumber(string columnTitle) {
        int result = 0;
        for(auto c:columnTitle){
            int diff = c-'A'+1;
            result = result*26 + diff;
        }
        return result;
    }


int main(){
   
    string str = "AB";
    cout<<titleToNumber(str);
    return 0;
}