//Online stock span
#include<bits/stdc++.h>
using namespace std;

void calculateSpan(int arr[],int n){
    vector<int> span(n);
    stack<int> st;
    int i=0;
    span[i] = 1;
    st.push(0);
    for(i=1;i<n;i++){
      while (!st.empty() and arr[st.top()]<=arr[i])
      {
          st.pop();
      }
      span[i] = st.empty()?(i+1):(i-st.top());
      st.push(i);
      
    }
    for(auto i:span){
        cout<<i<<" ";
    }
}
int main(){
    int price[] = {100,80,60,70,60,75,85};
    int n = sizeof(price)/sizeof(int);
    calculateSpan(price,n);
    return 0;
}