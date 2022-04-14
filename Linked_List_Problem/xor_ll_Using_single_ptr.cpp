#include<bits/stdc++.h>
using namespace std;
 
struct node
{
	struct node* npx;
	int data;
};
/* returns XORed value of the node addresses */
struct node* XOR(struct node* temp1,struct node* temp2)
{
	return (struct node*) ((uintptr_t) (temp1) ^ (uintptr_t) (temp2));/*uintptr_t is an unsigned integer type that is
																		 capable of storing a pointer*/
}
/*
push() function is used to add the node 
in the begining of the list and XOR operation 
is done in the push() function
*/
void push(struct node** head,int data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
 
	/*As the node is inserted in the
	starting of the list. So XOR operation is done for
	current head and NULL because in doubly linked list 
	left pointer of first node will NULL.
	*/
 
	new_node->npx=XOR(*head,NULL);
 
	/* If linked list is not empty, then npx of  
    current head node will be XOR of new node  
    and node next to current head */
	if(*head)
	{
		/* *(head)->npx is XOR of NULL and next.  
         So if we do XOR of it with NULL, we get next*/
		struct node* next=XOR((*head)->npx,NULL);
		(*head)->npx=XOR(new_node,next);
	}
	*head=new_node;
}
/*
prints values of doubly linked list in forward direction  
*/
void printList(struct node* head)
{
	struct node* curr=head;
	struct node* prev=NULL;
	struct node* next;	
	while(curr)
	{
		// print current node  
		printf("%d",curr->data);
        cout<<"->";
		/*Getting the next node value by doing 
		 XOR operation of prev and next pointer*/
		next=XOR(prev,curr->npx);
 
		prev=curr;
		curr=next;
	}
}
 
int main()
{
	struct node* head=NULL;
	/*
	Inserting the Values into Linked List
	*/
	push(&head,10);
	push(&head,9);
	push(&head,8);
	push(&head,7);
	push(&head,6);
 
	printList(head);
 
	return 0;
 
}