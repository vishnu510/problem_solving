#include<iostream>
using namespace std;

int main(){

    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
   int temp;
   for(int i=0;i<3;i++){

       for(int j=i;j<3;j++){
           if(i==j){
               matrix[i][j] = matrix[i][j];
           }
           temp = matrix[i][j];
           matrix[i][j] = matrix[j][i];
           matrix[j][i] = temp;
           
       }
   }
   for(int i=0;i<3;i++){
       int start =0;
       int end = 3-1;
       while(start<end){
           swap(matrix[i][start],matrix[i][end]);
           start++;
           end--;
       }
       
   }
   for(int i=2;i>=0;i--){

       for(int j=2;j>=0;j--){
         cout<<matrix[i][j]<<" ";
           
       }
       cout<<endl;
   }

    return 0;
}