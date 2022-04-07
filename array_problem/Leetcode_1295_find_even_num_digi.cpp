#include<bits/stdc++.h>
using namespace std;


int find_even_dig(int nums[],int n){
    int size = n;
    int c1=0;
    for(int i=0;i<size;i++){
        int num = nums[i],c2=0;
        while(num){
            num/=10;
            c2++;
        }
        if(c2%2==0){
            c1++;
        }
    }
    return c1;
}


int main(){

    int nums[] ={555,901,482,1771};
    int n = sizeof(nums)/sizeof(int);
    cout<<find_even_dig(nums,n);

    return 0;
}