//452. Minimum Number of Arrows to Burst Balloons
#include<bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end());
        int curr_inx = 0;
        int arrow = 0;
        for(int i=0;i<points.size();i++){
            if(arrow==0 || points[i][0]>curr_inx){
                arrow++;
                curr_inx = points[i][1];
            }
        }
        return arrow;
    }
int main(){

    vector<vector<int>> points ={{10,16},{3,4},{5,6},{7,8}};
    cout<<findMinArrowShots(points);
    return 0;
}    