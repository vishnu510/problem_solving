#include<bits/stdc++.h>
using namespace std;


int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
	int liveNeighbours = 0;
	if(i>0) {
		
		if(curr[i-1][j] == 1) liveNeighbours++;
	}
	if(i<m-1) {
		
		if(curr[i+1][j] == 1) liveNeighbours++;
	}
	if(j>0) {
		
		if(curr[i][j-1] == 1) liveNeighbours++;
	}
	if(j<n-1) {
	
		if(curr[i][j+1] == 1) liveNeighbours++;
	}

	if(i>0 && j>0) {
		if(curr[i-1][j-1] == 1) liveNeighbours++;
	}
	if(i>0 && j<n-1) {
		if(curr[i-1][j+1] == 1) liveNeighbours++;
	}
	if(i<m-1 && j>0) {
		if(curr[i+1][j-1] == 1) liveNeighbours++;
	}
	if(i<m-1 && j<n-1) {
		if(curr[i+1][j+1] == 1) liveNeighbours++;
	}
	return liveNeighbours;
}
int main(){
    vector<vector<int>> board{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	vector<vector<int>> curr = board;
	int m = board.size();
	int n = board[0].size();
	for(int i = 0; i<m; i++) {
		for(int j = 0; j<n; j++) {
			int ln = getLiveNeighbours(curr, i, j, m, n);
			if(board[i][j] == 0) {
				
				if(ln == 3) {
					board[i][j] = 1;
				}
			}
			else if(board[i][j] == 1) {
				
				if(ln < 2 || ln > 3) {
					board[i][j] = 0;
				}
			}
		}
	}

    for(int i = 0; i<m; i++) {
		for(int j = 0; j<n; j++) {
			cout<<board[i][j]<<" ";
		}
        cout<<endl;
	}

    

    return 0;
}