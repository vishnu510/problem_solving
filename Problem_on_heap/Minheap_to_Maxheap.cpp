#include<bits/stdc++.h>
using namespace std;


void MaxHeapify(int arr[], int i, int n)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if (l < n && arr[l] > arr[i])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, n);
    }
}
void convertMaxHeap(int arr[], int n)
{
    for (int i = (n-2)/2; i >= 0; --i)
        MaxHeapify(arr, i, n);
}
int main(){
     
     int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]); 
    convertMaxHeap(arr, n);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}