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
ListNode *divide(ListNode* &head){
    ListNode* p,*start_second;
    p = head->next->next;
    while (p)
    {
       head = head->next;
       p = p->next;
       if(p){
           p = p->next;
       }
    }
    start_second = head->next;
    head->next = NULL;
    return start_second;
}
ListNode *merge(ListNode* &head1,ListNode* &head2){
    ListNode *MergeList,*temp;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->val<=head2->val){
      MergeList = head1;
      head1 = head1->next;
    }
    else{
        MergeList = head2;
        head2 = head2->next;
    }
    temp  = MergeList;
    while (head1 and head2)
    {
        if(head1->val<=head2->val){
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }
    temp->next = (!head1)?head2:head1;
    return MergeList;   
}
ListNode *merge_sort(ListNode* &head){
    ListNode *start_f,*start_s,*start_merged;
    if(head and head->next){
        start_f = head;
        start_s = divide(head);
        start_f = merge_sort(start_f);
        start_s = merge_sort(start_s);
        start_merged = merge(start_f,start_s);
        return start_merged;
    }
    else{
        return head;
    }
}
int main(){
   ListNode* List1 = NULL;
   insert_node(List1,2);
   insert_node(List1,1);
   insert_node(List1,3);
   insert_node(List1,6);
   insert_node(List1,4);
   insert_node(List1,7);
   insert_node(List1,6);
   printList(List1);
   cout<<endl;
   List1 = merge_sort(List1);
   printList(List1);
  
   return 0;
}