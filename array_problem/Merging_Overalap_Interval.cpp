#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> nums{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    res.push_back(nums[0]);
   
    for(int i=0;i<nums.size();i++){

        if(res.back()[1] >= nums[i][0]) res.back()[1] = max(res.back()[1] , nums[i][1]);
            else res.push_back(nums[i]); 
    }
    for(int i=0;i<res.size();i++){
        for(int j=0;j<2;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    // Other approach using stack pus the element in stack and pop them and copare them with arr current element 
    // and modify accordingly
    
    

    return 0;
}