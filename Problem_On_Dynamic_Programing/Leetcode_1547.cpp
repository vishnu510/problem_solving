//1547. Minimum Cost to Cut a Stick

#include<bits/stdc++.h>
using namespace std;

 int memo[101][101];
    int dp(int i,int j,vector<int>& cuts,int start,int end)
    {
        if(i>=j)
            return 0;
        else if(memo[i][j]!=-1)
            return memo[i][j];
        else
        {
            int q=INT_MAX;
            for(int k=i;k<j;++k)
                q=min(q,end-start+dp(i,k,cuts,start,cuts[k])+dp(k+1,j,cuts,cuts[k],end));
            return memo[i][j]=q;
        }
    }
    int minCost(int n, vector<int>& cuts) 
    {
        sort(cuts.begin(),cuts.end());
        memset(memo,-1,sizeof(memo));
        return dp(0,cuts.size(),cuts,0,n);
    }
int main(){

    vector<int> cuts = {1,3,4,5};
    cout<<minCost(7,cuts);
    return 0;
}