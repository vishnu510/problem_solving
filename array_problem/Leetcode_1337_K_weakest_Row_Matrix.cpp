#include<bits/stdc++.h>
using namespace std;



int main(){
    
    // this approach will take O(M*N) time and O(N+K) space
    vector<vector<int>> mat{{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    int row = mat.size();
    int col = mat[0].size();
   
    vector<pair<int,int>> res(row);

        for(int i = 0;i<row;i++){
             int count=0;
            for(int j=0;j<col;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            res[i] = make_pair(count,i);
        }
        sort(res.begin(),res.end());
        cout<<"[";
        for(int i=0;i<3;i++){
            cout<<" "<<res[i].second<<",";
        }
        cout<<"]"<<endl;;
        
        
    return 0;
}