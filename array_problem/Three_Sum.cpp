#include<bits/stdc++.h>
using namespace std;

int main(){
    int nums[]= {-1,0,1,2,-1,-4};
    int n = sizeof(nums)/sizeof(int);

    //This is brute force approach takes O(n^3) time  
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(i!=j and j!=k and i!=k and (nums[i] +nums[j]+nums[k])==0){
                    cout<<"["<<nums[i]<<","<<nums[j]<<","<<nums[k]<<"]"<<endl;
                }
            }
        }

    }
cout<<endl;
   
    vector<int> num{-1,0,1,2,-1,-4};
    int siz = sizeof(num)/sizeof(int);
    sort(num.begin(),num.end());
    int left,right,curr_sum=0;
    vector<int> res;
    for(int i=0;i<siz;i++){
        left = i+1;
        right = siz-1;
        while(left<right)
      {
          curr_sum = num[i]+num[left]+num[right];
        if(curr_sum==0)
        {
            cout<<"["<<num[i]<<","<<num[left]<<","<<num[right]<<"]"<<endl;
            left++;
            right--;
        }
       
        else if(curr_sum<0)
        {
            left++;
        }
        else
        {
            right--;
        }
      }

    }
    return 0;
}