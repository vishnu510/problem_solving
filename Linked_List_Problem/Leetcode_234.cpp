// Linked list Palindrome
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

bool find_Palindrome(ListNode* &head){
   stack<int> st;
   bool flag = false;
    ListNode* temp1 = head;
   while (temp1!=NULL)
   {   
      
       st.push(temp1->data);
        temp1 = temp1->next;
   }
   ListNode* temp2 = head;
   while (temp2!=NULL)
   {   
       
       if(st.top()==temp2->data){
           flag = true;
       }
       temp2 = temp2->next;
       st.pop();
   }
 
   return flag;
   
}

ListNode* findMid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL,*curr=head,*temp=NULL;
        while(curr != NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool compareList(ListNode* head1, ListNode* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->data != head2->data) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* h=head;
        ListNode* mid = findMid(h);
        ListNode* h2=reverseList(mid);
        return compareList(head,h2);
    }

int main(){

    //this approach takes O(n) time and O(n) space
    ListNode* head = NULL;
    insertion_at_Tail(head,1);
    insertion_at_Tail(head,2);
    insertion_at_Tail(head,3);
    insertion_at_Tail(head,2);
    insertion_at_Tail(head,1);
    insertion_at_Tail(head,3);
    cout<<find_Palindrome(head)<<endl;

    // another appoach time O(n) space O(1)
    cout<<isPalindrome(head)<<endl;
    return 0;
}