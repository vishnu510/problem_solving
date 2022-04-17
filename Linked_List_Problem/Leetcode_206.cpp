// Reverse linked list
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};
void insert_node(ListNode* &head,int data){
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

void printList(ListNode* &head){
    ListNode* temp = head;
    cout<<"List:"<<" ";
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    
}
ListNode *revList(ListNode* &head){
    ListNode* curr = head;
    ListNode* next;
    ListNode * prev = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main(){
   ListNode* List1 = NULL,*rev=NULL;
   insert_node(List1,1);
   insert_node(List1,2);
   insert_node(List1,3);
   insert_node(List1,4);
   insert_node(List1,5);
   printList(List1);
   rev = revList(List1);
   cout<<endl;
   printList(rev);
   return 0;
}