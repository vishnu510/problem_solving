#include<bits/stdc++.h>
using namespace std;
stack<int> stk3;

void insert_at_bottom(int x){
    if(stk3.size()==0){
        stk3.push(x);
    }
    else{
        int a = stk3.top();
        stk3.pop();
        insert_at_bottom(x);
        stk3.push(a);
    }
}
void reverse(){
    if(stk3.size()>0){
        int x = stk3.top();
        stk3.pop();
        reverse();
        insert_at_bottom(x);
    }

}
int main(){
    stack<int> stk1;
    stk1.push(7);
    stk1.push(6);
    stk1.push(4);
    stk1.push(4);
    stk1.push(3);
    stk1.push(2);
    stk1.push(1);
    stack<int> stk2;
   cout<<"First Approach reverse stack using 2 stack------"<<endl;
    cout<<"Before Reverse:";
    while(stk1.size()!=0){
       cout<<stk1.top()<<" ";
       stk2.push(stk1.top());
       stk1.pop();
    }
    cout<<endl;
    cout<<"After Reverse:";
    while(stk2.size()!=0){
       cout<<stk2.top()<<" ";
       stk2.pop();
    }
    cout<<endl;
    cout<<"Second Approach using recusrion----"<<endl;
    stk3.push(7);
    stk3.push(6);
    stk3.push(5);
    stk3.push(4);
    stk3.push(3);
    stk3.push(2);
    stk3.push(1);
    stack<int> stk4;
    stk4.push(7);
    stk4.push(6);
    stk4.push(5);
    stk4.push(4);
    stk4.push(3);
    stk4.push(2);
    stk4.push(1);
    int n = stk3.size();
    cout<<"Before Reverse:";
    while(stk4.size()!=0){
       cout<<stk4.top()<<" ";
       stk4.pop();
    }
    cout<<endl;
    cout<<"After Reverse:";
    reverse();
    while(stk3.size()!=0){
       cout<<stk3.top()<<" ";
       stk3.pop();
    }

    return 0;
}