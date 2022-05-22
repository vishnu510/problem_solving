//973. K Closest Points to Origin
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        if(points.size()==0) return ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(pq.size()<k){
              pq.push({distance,{points[i][0],points[i][1]}});
            }
            else{
                if(distance<pq.top().first){
                    pq.pop();
                    pq.push({distance,{points[i][0],points[i][1]}});
                }
            }
        }
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }

int main(){

    vector<vector<int>> points = {{1,3},{-2,2}};
    vector<vector<int>> answer = kClosest(points,1);
    cout<<"[";
    for(int i=0;i<answer.size();i++){
        cout<<"[";
        for(int j=0;j<answer[0].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<"]";
    }
   cout<<"]";
    return 0;
}