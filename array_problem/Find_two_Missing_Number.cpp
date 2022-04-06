#include<bits/stdc++.h>
using namespace std;

int main(){

    // this approach take O(n) time and (n) space

    int nums[] = {9,6,4,2,3,5,7,0,1};
    int n = sizeof(nums)/sizeof(int);
    int m=n+2;
    vector<int> out(m,0);
    for(int i=0;i<m;i++){
        out[nums[i]]=1;
    }
    for(int j=0;j<m;j++){
        if(out[j]==0){
            cout<<j<<" ";
        }
    }
    cout<<endl;
    
   
    return 0;
}