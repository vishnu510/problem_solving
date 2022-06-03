//785. Is Graph Bipartite?
#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n,0);
    queue<int> vis;
    for(int i=0;i<n;i++){
        if(colors[i]){
            continue;
        }
        colors[i] = 1;
        vis.push(i);
        while (!vis.empty())
        {
            int temp = vis.front();
            for(auto neighbor:graph[temp]){
                if(!colors[neighbor]){
                    colors[neighbor] = -colors[temp];
                    vis.push(neighbor);
                }
                else if(colors[neighbor]==colors[temp]){
                    return false;
                }
            }
            vis.pop();
        }
        
    }
    return true;
}

int main(){

    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout<<isBipartite(graph);
    return 0;
}