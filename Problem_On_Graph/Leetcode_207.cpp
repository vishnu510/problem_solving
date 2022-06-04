//207. Course Schedule
#include<bits/stdc++.h>
using namespace std;
int white=0; // unvisited
int gray = 1; // incomplete
int black =2; // visited

bool dfs(int node,vector<vector<int>>& graph,vector<int>&visited){
    visited[node] =gray;
    for(int j=0;j<graph[node].size();j++){
        if(visited[graph[node][j]]==gray){
            return false;
        }
        if(visited[graph[node][j]]==white){
            if(!dfs(graph[node][j],graph,visited)) return false;
        }
    }
    visited[node] = black;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> visited(numCourses,white);
    for(int i=0;i<prerequisites.size();i++){
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for(int i=0;i<numCourses;i++){
        if(visited[i]==white){
            if(!dfs(i,graph,visited)) return false;
        }
    }
    return true;
}

int main(){

    vector<vector<int>> prerequisites = {{1,0}};
    int numCourses = 2;
    cout<<canFinish(numCourses,prerequisites);

    return 0;
}