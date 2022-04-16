#include<bits/stdc++.h>
using namespace std;

class ListNode
{   
    public:
	int data;
	ListNode* next;
    ListNode(int val){
        data =val;
        next = NULL;
    }
};
 
/* Function to splitList() splits the list into two circular lists
	head1 holds first circular list and head2 holds second circular list
*/
void splitList(ListNode *head, ListNode **head1,ListNode **head2) 
{ 
  ListNode *slowptr = head; 
  ListNode *fastptr = head;  
 
  if(head == NULL) 
  {
    return; 
   }
 
  while(fastptr->next != head && fastptr->next->next != head)  
  { 
     fastptr = fastptr->next->next; 
     slowptr = slowptr->next; 
  }   
  if(fastptr->next->next == head) {  
      fastptr = fastptr->next; 
      }      
  *head1 = head;     
  if(head->next != head) 
    {
        *head2 = slowptr->next; 
    }
   
  fastptr->next = slowptr->next; 
  slowptr->next = head;        
} 

void push(ListNode** head,int data)
{
	ListNode* new_node=new ListNode(data);
	ListNode *temp = *head;
	new_node->data=data;
	new_node->next=*head;
 
	if(*head != NULL) 
  	{ 
    while(temp->next != *head) 
      	temp = temp->next;         
    temp->next = new_node;  
  	}
 
  	else
  	new_node->next=new_node;
  	*head=new_node; 
 
}

void printList(ListNode* head)
{
	ListNode* temp=head;
	do
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}while(temp!=head);
 
	cout<<endl;
}
 
int main()
{
 
	ListNode* head=NULL;
	ListNode* head1=NULL;
	ListNode* head2=NULL;
 
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
    cout<<"Original List:"<<" ";
	printList(head);
	splitList(head,&head1,&head2);
	cout<<"First List:"<<" ";
	printList(head1);
	cout<<"First List:"<<" ";
	printList(head2);
}