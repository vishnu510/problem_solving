// find maximum height of a rectangle in histogram
#include<bits/stdc++.h>
using namespace std;

int findLeftIndex(vector<int>& heights,int i){
        int j = i-1;
        while(j>=0 and heights[j]>=heights[i]){
            j-=1;
        }
        return j;
    }
    int findRightIndex(vector<int>& heights,int i){
        int j = i+1;
        while(j<heights.size() and heights[j]>=heights[i]){
            j+=1;
        }
        return j;
    }
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if(n==0){
        return 0;
    }
    int maxArea =-1;
    for(int i=0;i<n;i++){
        int leftInd = findLeftIndex(heights,i);
        int rightInd = findRightIndex(heights,i);
        int curr_area = (rightInd-leftInd-1)*heights[i];
        if(maxArea<curr_area){
            maxArea = curr_area;
        }
    }
     return maxArea;   
    }
int main(){
    vector<int> heights{2,1,5,6,2,};
    int ans =largestRectangleArea(heights);
    cout<<ans;
    return 0;
}