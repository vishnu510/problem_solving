// strapping rain water
#include<bits/stdc++.h>
using namespace std;

// using stack O(n) space and O(n) time
int trap(vector<int > height){
  int len =height.size();
  stack<int> st;
  int res =0;
  int top,dist,boundHeight;
for(int i=0;i<len;i++){
    while (!st.empty() and height[i]>height[st.top()])
    {
       top = st.top();
       st.pop();
       if(st.empty()){
           break;
       }
        dist = i- st.top()-1;
        boundHeight = min(height[i],height[st.top()])-height[top];
        res+=(dist*boundHeight);
    }
    st.push(i);
}
return res;
}
// O(1) space and O(n) time
int trapWater(vector<int > height){
   int len = height.size();
   int leftMax = 0,rightMax=0,left=0,right=len-1,result=0;
   while (left<right)
   {
       if(height[left]<height[right]){
           if(height[left>=leftMax])
               leftMax = height[left];
           
           else
               result+=(leftMax-height[left]);
           
            left+=1;
       }
      
       else{
           if(height[right]>=rightMax)
               rightMax = height[right];
           
           else
               result+=(rightMax-height[right]);
           
          right-=1;
       }
        
   }
   return result;
}
int main(){
    vector<int > height{0,1,0,2,1,0,1,3,2,1,2,1};
    int size = height.size();
    vector<int> left(size,0);
    vector<int> right(size,0);
    int answer=0,l=height[0],m=height[size-1];
    for (int i = 0; i < size; i++)
    {
        left[i] = max(l,height[i]);
        l = max(l,height[i]);
    }
    for (int i = size-1; i >=0 ; i--)
    {
        right[i] = max(m,height[i]);
        m = max(m,height[i]);
    }
    for (int i = 0; i < size; i++)
    {
        answer+= min(left[i],right[i])-height[i];
    }
    cout<<answer<<endl;;
    int ans = trap(height);
    cout<<ans<<endl;
    int result = trapWater(height);
    cout<<result;
    return 0;
}