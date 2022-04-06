#include<bits/stdc++.h>
using namespace std;

int main(){
    int array[] ={17,18,5,4,6,1};

    //Replace every element to their greatest element in the right side
    
    int n = sizeof(array)/sizeof(int);
    
    // Brute force approach
    
    for(int i=0;i<n-1;i++){
        int maxi=0;
        for (int  j = i+1; j < n; j++)
        {
            maxi = max(maxi,array[j]);
        }
        array[i] = maxi;
    }
    array[n-1] = -1;
    for(int i=0; i < n; i++){
        cout<<array[i]<<",";
    } 
    cout<<endl;
   // Optimal approach
   
int arr[] ={17,18,5,4,6,1};

   int max_ele =-1;
    int temp = 0;
    
   for(int i = n-1;i>=0;i--){
       
       temp = arr[i];
       arr[i] = max_ele;
       max_ele = max(temp,max_ele);

   }
    for(int i=0; i < n; i++){
        cout<<arr[i]<<",";
    } 

    return 0;
}