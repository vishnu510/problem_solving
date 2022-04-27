// Implent stack using queue
#include<bits/stdc++.h>
using namespace std;
class mystack{
    public:
    mystack(){
    
    }
queue<int> q1;
queue<int> q2;
void push(int data){
  q2.push(data);
  while(!q1.empty()){
      q2.push(q1.front());
      q1,pop();
  }
  swap(q1,q2);
}
int32_t pop(){
    int res = top();
    q1.pop();
    return res;
}
int top(){
    return q1.front();
}
bool empty(){
    return q1.empty();
}
};
int main(){
    mystack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.top();

    return 0;
}