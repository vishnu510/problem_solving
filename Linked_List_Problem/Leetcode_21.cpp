// Merge two sorted linked list
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

ListNode* mergeList(ListNode* &list1,ListNode* &list2){
    ListNode* mergeNode,*temp;
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    if(list1->val<=list2->val){
        mergeNode = list1;
        list1 = list1->next;
    }
    else{
        mergeNode = list2;
        list2 = list2->next;
    }
     temp =mergeNode;
     while (list1 and list2)
     {
         if(list1->val<=list2->val){
             temp->next = list1;
             temp = temp->next;
             list1 = list1->next;
         }
         else{
            temp->next = list2;
             temp = temp->next;
             list2 = list2->next;
         }
     }
     temp->next = (!list1)?list2:list1;
     return mergeNode;
}
int main(){
   ListNode* List1 = NULL,*List2=NULL,*List3 =NULL;
   insert_node(List1,1);
   insert_node(List1,2);
   insert_node(List1,3);
   insert_node(List1,5);
   insert_node(List1,6);
   printList(List1);
   cout<<endl;
   insert_node(List2,4);
   insert_node(List2,7);
   insert_node(List2,8);
   insert_node(List2,9);
   printList(List2);
   cout<<endl;
   printList(List3 =mergeList(List1,List2));
   
   return 0;
}