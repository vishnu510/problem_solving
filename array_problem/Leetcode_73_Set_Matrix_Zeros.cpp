#include<bits/stdc++.h>
using namespace std;



int main(){
    
    // this approach will take O(M*N) time and O(M+N) space
    vector<vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};

        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<pair<int,int>> curr;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    curr.push_back({i,j});
                }
            }
        }
        for(int i=0;i<curr.size();i++){
            int m = curr[i].first;
            int n = curr[i].second;
            int r =0,c=0;
            while(r<row){
                matrix[r][n] = 0;
                r++;
            }
            while(c<col){
                matrix[m][c] = 0;
                c++;
            }
        }
   cout<<"[";
    for(int i=0;i<matrix.size();i++){
        cout<<"["<<" ";
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<",";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;

    // this approach will take O(M*N) time and O(1) space 

    vector<vector<int>> mat{{1,1,1,0},{1,1,0,1},{1,1,1,1}};
    int rows = mat.size();
    int column = mat[0].size();
    bool row_flag=false,col_flag=false;

    for(int i=0;i<rows;i++){
        for(int j=0;j<column;j++){
            if(i==0 and mat[i][j]==0){
                row_flag = true;
            }
            if(j==0 and mat[i][j]==0){
                col_flag = true;
            }
            if(mat[i][j]==0){
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }
    
    for(int i=1;i<rows;i++){
        for(int j=1;j<column;j++){
           if(mat[i][0]==0 or mat[0][j]==0){
               mat[i][j] = 0;
           }
        }
    }
    if(row_flag){
        for(int i=0;i<column;i++){
            mat[0][i] = 0;
        }
    }
    if(col_flag){
        for(int i=0;i<rows;i++){
            mat[i][0] = 0;
        }
    }
    cout<<"[";
    for(int i=0;i<mat.size();i++){
        cout<<"["<<" ";
        for(int j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<",";
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
}