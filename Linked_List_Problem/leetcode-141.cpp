#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int d) {
        data = d;
        next = NULL;
    }
};

void insertion_at_Tail(ListNode* &head, int data) {
    if (head == NULL) {
        ListNode* node = new ListNode(data);
        head = node;
        return;
    }
    ListNode* temp = head;
    ListNode* node = new ListNode(data);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

bool find_loop(ListNode* &head){
    if(head==NULL){
        return false;
    }
    ListNode* slow =head;
    ListNode* fast =head;
    while(slow and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
int main(){
    ListNode* head = NULL;
    insertion_at_Tail(head,1);
    insertion_at_Tail(head,2);
    insertion_at_Tail(head,3);
    ListNode* p = head;
    while (p->next)
    {
        p = p->next;
    }
     insertion_at_Tail(head,4);
    insertion_at_Tail(head,5);
    insertion_at_Tail(head,6);
    ListNode* q = head;
    while (q->next)
    {
        q = q->next;
    }
    q->next=p;
    
    cout<<find_loop(head)<<endl;
    return 0;
}