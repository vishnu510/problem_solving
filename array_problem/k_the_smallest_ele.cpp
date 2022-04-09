#include<bits/stdc++.h>
using namespace std;

int find_kth_smallest_ele(int nums[],int n,int k){
      int largest = -1;
    for(int i =0;i<n;i++){
        largest = max(largest,nums[i]);
    }
    //create a count numsay/vector
    vector<int> freq(largest+1,0);
    //update the freq numsay
    for(int x =0;x<n;x++){
        freq[nums[x]]++;
    }
    int j=0;
    for(int i=0;i<=largest;i++){
       while(freq[i]>0){
           nums[j]=i;
           freq[i]--;
           j++;
       }
    }
    return nums[k];
}


int main(){

    int nums[] = {13,12,11,14,15,17,18,20,19,16};
    int n=sizeof(nums)/sizeof(int);
    int num =5;
    cout<<find_kth_smallest_ele(nums,n,num)<<endl;

    // other Approach finding kth largest element using min head periority queue
    vector<int> number {3,2,1,5,6,4};
    int size=sizeof(nums)/sizeof(int);
    int numb =2;
    priority_queue<int> pq(number.begin(),number.end());
    for(int i=0;i<numb;i++){
        pq.pop();
    }
    cout<<pq.top()<<endl;

    //Find largest element using min-head multiset
    vector<int> arr {3,2,3,1,2,4,5,5,6};
    multiset<int> mset;
    int in =2;
    for(int num: arr){
        mset.insert(num);
        if(mset.size()>in){
                mset.erase(mset.begin());
        }
    }
    cout<<*mset.begin();


    return 0;
}