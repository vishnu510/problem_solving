#include<bits/stdc++.h>
using namespace std;
#define N 4

bool isSafeMaze(int maze[N][N],int x,int y){
    if(x>=0 and x<N and y>=0 and y<N and maze[N][N]==1){
        return true;
    }
    return false;
}
bool solveUntilMaze(int maze[N][N],int row,int col,int res[N][N]){
    if (row == N - 1 && col == N - 1 && maze[row][col] == 1) {
        res[row][col] = 1;
        return true;
    }
    if(isSafeMaze(maze,row,col)==true){
        if(res[row][col]==1){
            return false;
        }
        res[row][col]=1;
        if(solveUntilMaze(maze,row+1,col,res)==true){
            return true;
        }
        if(solveUntilMaze(maze,row,col+1,res)==true){
            return true;
        }
        res[row][col] = 0;
        return false;
    }
    return false;
}
void printRes(int res[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveMaze(int maze[][4]){
   int res[N][N]={{0,0,0,0},
               {0,0,0,0},
               {0,0,0,0},
               {0,0,0,0}};
    if(solveUntilMaze(maze,0,0,res)==false){
        return false;
    }
    printRes(res);
    return true;           
}

int main(){
    
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    solveMaze(maze);
    return 0;
}