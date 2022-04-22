#include<bits/stdc++.h>
using namespace std;

class MinStack {

    stack<int> s1;
    stack<int> s2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() || val<=s2.top()){
            s2.push(val);
        }
        
    }
    
    void pop() {
        if(s1.top()==s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top(); 
    }
};

int main(){
    MinStack obj;
    obj.push(3);
    obj.push(2);
    obj.push(1);
    obj.push(5);
    obj.push(4);
    obj.push(7);
    obj.push(6);
    cout<<obj.top()<<endl;
    cout<<obj.getMin();

}