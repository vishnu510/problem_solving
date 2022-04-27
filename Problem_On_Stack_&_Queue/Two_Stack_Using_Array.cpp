#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
int arr[MAXSIZE];
int top = -1;
int top2 = MAXSIZE;
void push1(int x){
   if(top<top2-1){
      arr[++top] = x;
   }
   else{
       cout<<"Stack is Overflow"<<endl;
   }

}
int pop1(){
    if(top>=0){
        return arr[top--];
    }
    else{
        cout<<"Stack is Underflow"<<endl;
    }
}
void push2(int x){
    if(top<top2-1){
      arr[--top2] = x;
   }
   else{
       cout<<"Stack is Overflow"<<endl;
   }

}
int pop2(){
    if(top2<=MAXSIZE){
        return arr[top2++];
    }
    else{
        cout<<"Stack is Underflow"<<endl;
    }
}
int main(){
    push1(40);
    push1(45);
    push1(50);
    push1(60);
    push2(80);
    push2(75);
    push2(70);
    push2(60);
    printf("%d",pop1());
    cout<<endl;
    printf("%d",pop2());
    return 0;
}