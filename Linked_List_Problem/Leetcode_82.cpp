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
ListNode* remove_duplicate(ListNode* &head){
    ListNode* dummyNode  = new ListNode(0);
    dummyNode->next = head;
    ListNode* prev = dummyNode;
    while(head!=NULL){
        if(head->next!=NULL and head->data == head->next->data){
            while(head->next!=NULL and head->data == head->next->data){
                head = head->next;
            }
            prev->next = head->next;
        }
        else{
            prev = prev->next;
        }
        head = head->next;
    }
    return dummyNode->next;
}

int main(){

    ListNode* List1 =NULL;
    insert(List1,1);
    insert(List1,2);
    insert(List1,2);
    insert(List1,3);
    insert(List1,3);
    insert(List1,4);
    insert(List1,4);
    insert(List1,5);
    printList(List1);
    ListNode* List2 = remove_duplicate(List1);
    cout<<endl;
    printList(List2);
    
    
}