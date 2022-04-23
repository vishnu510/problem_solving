#include<bits/stdc++.h>
using namespace std;

void nextGreatestEle(int arr[],int size){
    stack<int> st;
    int element,next;
    int i=0;
    st.push(arr[i]);
    for(i=1;i<size;i++){
        next = arr[i];
        if(!st.empty()){
            element = st.top();
            st.pop();
            while (element<next)
            {
                cout<<element<<" "<<next<<endl;
                if(st.empty()){
                    break;
                }
                element = st.top();
                st.pop();
            }
            if(element>next){
                st.push(element);
            }

        }
        st.push(next);
    }
    while (!st.empty())
    {
        element = st.top();
        st.pop();
        next = -1;
        cout<<element<<" "<<next<<endl;
    }
    
}

int main(){
    int arr[] = {15,12,16,2,1,0,7,8};
    int n = sizeof(arr)/sizeof(int);
    nextGreatestEle(arr,n);
    return 0;
}