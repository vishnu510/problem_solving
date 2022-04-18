#include <bits/stdc++.h>
using namespace std;
 
// A Linked List Node
class ListNode
{
    public:
    int data;
    ListNode *right;
    ListNode *down;
    ListNode(int d){
        d = data;
        right = NULL;
        down = NULL;
    }
};
 
void push (ListNode* &head, int new_data)
{
    ListNode* new_node = new ListNode(new_data);
    new_node->right = NULL;
    new_node->data = new_data;
    new_node->down = head;
    head = new_node;
}
 
/*  print nodes in the flattened linked list */
void printList(ListNode *head)
{
    while (head)
    {
        cout<<head->data<<"->";
        head = head->down;
    }
}
 
// A utility function to merge two sorted linked lists
ListNode* merge( ListNode* head1, ListNode* head2 )
{
 
    if (!head1)
        return head2;
    if (!head2)
        return head1;
 
    // Compare the data members of head nodes of both lists
    // and put the smaller one in result
    ListNode* result=NULL;
    ListNode* temp=NULL;
    if(head1->data < head2->data){
        result=temp=head1;
        head1=head1->down;
    }
        else{
        result = temp = head2;
        head2 = head2->down;
    }
    while(head1 && head2){
        if(head1->data < head2->data){
           temp->down=head1;
           temp=head1;
           head1=head1->down;
        }
        else{
           temp->down=head2;
           temp=head2;
           head2=head2->down;
        }
    }
    temp->down = head1 ?head1: head2;
    return result;
}
 
// flattens a given linked list
ListNode* flatten (ListNode* &head)
{
    // Base cases
    if (!head|| !head->right)
        return head;
 
    ListNode *rem=head->right;
    ListNode *newh=head;
    while(rem){
        ListNode *l2=rem;
        rem=rem->right;
        newh=merge(newh,l2);
    }
    return newh;
}
 
// Driver program to test above functions
int main()
{
    ListNode* head = NULL;
 
 
    push(head, 30 );
    push(head, 8 );
    push(head, 7 );
    push(head, 5 );
 
    push(( head->right ), 20 );
    push(( head->right ), 10 );
 
    push(( head->right->right ), 50 );
    push(( head->right->right ), 22 );
    push(( head->right->right ), 19 );
 
    push(( head->right->right->right ), 45 );
    push(( head->right->right->right ), 40 );
    push(( head->right->right->right ), 35 );
    push(( head->right->right->right ), 20 );
 
    // Let us flatten the list
    head = flatten(head);
 
    // Let us print the flatened linked list
    printList(head);
 
    return 0;
}