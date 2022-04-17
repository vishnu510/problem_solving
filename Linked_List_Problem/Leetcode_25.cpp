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
// it will reverse k ele of group and the traverse k ele ment and then reverse and so on
ListNode *revkList(ListNode* &head,int k){
    ListNode* curr =head;
    ListNode* next;
    ListNode* prev = NULL;
    int count = 0;
    while (curr!=NULL and count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(head!=NULL){
        head->next = curr;
    }
    count = 0;
    while(count<k-1 and curr!=NULL){
        curr = curr->next;
        count++;
    }
    if(curr!=NULL){
        curr->next = revkList(curr->next,k);
    }
    return prev;

}
// it will reverse in the group of k
 ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
int main(){
   ListNode* List1 = NULL,*List2 =NULL,*rev=NULL;
   insert_node(List1,1);
   insert_node(List1,2);
   insert_node(List1,3);
   insert_node(List1,4);
   insert_node(List1,5);
   insert_node(List2,1);
   insert_node(List2,2);
   insert_node(List2,3);
   insert_node(List2,4);
   insert_node(List2,5);
   printList(List1);
   rev = revkList(List1,3);
   cout<<endl;
   printList(rev);
   List2 = reverseKGroup(List2,2);
   cout<<endl;
   printList(List2);
   return 0;
}