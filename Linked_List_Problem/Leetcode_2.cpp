// Add two number in linked list

#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};

void insert_node_head(ListNode* &head,int val){
    if (head == NULL) {
        ListNode* node = new ListNode(val);
        head = node;
        return;
    }
    ListNode* node = new ListNode(val);
    node->next = head;
    head = node;
}
void insertion_at_Tail(ListNode*& head, int val) {
    if (head == NULL) {
        ListNode* node = new ListNode(val);
        head = node;
        return;
    }
    ListNode* temp = head;
    ListNode* node = new ListNode(val);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}
void print_ll(ListNode* &head){
  ListNode* temp = head;
  while(temp){
      cout<<temp->val<<"->";
      temp = temp->next;
  }

}
ListNode* addTwoLists(ListNode* &l1, ListNode* &l2)
{
    
    ListNode* res = NULL;
    ListNode *temp, *prev = NULL;
    int carry = 0, sum;
 
   
    while (l1 != NULL || l2 != NULL) {
        
        sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      
        carry = (sum >= 10) ? 1 : 0;
       
        sum = sum % 10;
    
        temp = new ListNode(sum);
       
        if (res == NULL)
            res = temp;
       
        else
            prev->next = temp;
    
        prev = temp;
 
        
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry > 0)
        temp->next = new ListNode(carry);
    return res;
}
int main(){

    ListNode* l1 = NULL,*l2 = NULL,*res =NULL;
    insertion_at_Tail(l1,1);
    insertion_at_Tail(l1,2);
    insertion_at_Tail(l1,8);
    insertion_at_Tail(l1,5);
    insertion_at_Tail(l1,7);
    insertion_at_Tail(l1,9);
    insertion_at_Tail(l1,9);
    insertion_at_Tail(l2,1);
    insertion_at_Tail(l2,2);
    insertion_at_Tail(l2,4);
    insertion_at_Tail(l2,5);
    insertion_at_Tail(l2,3);
    print_ll(l1);
    cout<<endl;
    print_ll(l2);
    res = addTwoLists(l1, l2);
    cout<<endl;
    print_ll(res);
    return 0;
}