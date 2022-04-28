// strapping rain water
#include<bits/stdc++.h>
using namespace std;
// using stack
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
    cout<<ans;
    return 0;
}