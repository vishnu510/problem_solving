#include<bits/stdc++.h>
using namespace std;



int main(){
    
    // this approach will take O(M*N) time and O(1) space
    vector<vector<int>> matrix{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
        int row = matrix.size();
        int col = matrix[0].size();
        int count=0;

        for(int i = 0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]<0){
                    count++;
                }
            }
        }
        cout<<count<<endl;

        // this approach will take O(M+N) time and O(1) space
    vector<vector<int>> grid{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
        int rows = grid.size();
        int column = grid[0].size();
        int count1=0;
        int i=rows-1,j=0;
        while(i>=0 and j<column){
            if(grid[i][j]<0){
                count1+=(column -j);
                i--;
            }
            else{
                j++;
            }
        }
        cout<<count1;
        
        
    return 0;
}