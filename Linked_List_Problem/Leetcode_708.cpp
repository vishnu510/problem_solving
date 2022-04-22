//Inserted Into sorted circular List
// Remove the dublicates element in sorted linked list
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int d){
        data = d;
        next = NULL;
    }
};
void insert(ListNode* &head,int data){
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
    ListNode* temp =head;
    cout<<"List :";
    while (temp)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    
}
void insert_in(ListNode* &head,int data){
    ListNode* temp = head;
    while(temp->data<data){
        temp = temp->next;
    }
    ListNode* node = new ListNode(data);
    temp->next = node;
    node->next = temp->next->next;
     
}

int main(){

    ListNode* List1 =NULL;
    insert(List1,1);
    insert(List1,3);
    insert(List1,4);
    insert(List1,5);
    insert(List1,7);
    insert(List1,8);
    printList(List1);
    ListNode* temp = List1;
    while(temp){
        temp = temp->next;
    }
    temp->next = List1;
    
    insert_in(List1,9);
}