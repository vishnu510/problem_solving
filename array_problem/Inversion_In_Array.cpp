#include<bits/stdc++.h>
using namespace std;

int mergeCountSort(int arr1[],int low,int mid,int high,int len1){
      int count1 = 0;
      int i = low , j = mid +1,k=0,siz=len1;
       int temp[siz];
       for(int i=0;i<siz;i++){
          temp[i] = arr1[i];
       }
       while(i<=mid and j<=high){
         
            if(arr1[i]>arr1[j]){
                count1 = count1 + (mid-i +1);
                temp[k++] = arr1[j++]; 
            }
            else{
                temp[k++] = arr1[j++];
            }

       }
       
       while (i<=mid)
       {
           temp[k++] = arr1[i++];
       }
       while (j<=high)
       {
           temp[k++] = arr1[j++];
       }
       for(int i=0;i<siz;i++){
          arr1[i] = temp[i];
       }
    return count1;
}
int countInversion(int arr[],int low,int high){
    int i =low ,j=high;
    int count =0;
    while(i<j and arr[i]>arr[j]){
        count = count + (j-1+1);
         i++;
    }
   return count;

}

int main(){

        // This approach take O(n^2) time 
     
      int arr[] = {2,5,1,7,9};
      int len = sizeof(arr)/sizeof(int);
      int count = 0;
      for(int i =0; i<len-1; i++){

          for(int j = i+1; j<len; j++){

              if(i<j and arr[i] > arr[j]){
                  count++;
              }

          }
      }
       cout<<count;
       
       cout<<endl;
       // let's try some other approach for better time complexity
       
      int arr1[] = {2,5,1,7,9};
      int len1 = sizeof(arr)/sizeof(int);
      
      int low=0,high=len1,mid=low +(high-low)/2;
      int l = countInversion(arr1,low,mid);
      int r = countInversion(arr1,mid+1,high);
      int m=mergeCountSort(arr1,low,mid,high,len1);
      cout<<(l + r + m);
    return 0;
}