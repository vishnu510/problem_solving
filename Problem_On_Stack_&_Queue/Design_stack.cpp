#include <iostream>
using namespace std;

struct node 
{
	int data;
	struct node *prev, *next;
};

struct stack
{
	struct node *head, *middle;
	int count;
};

/*create a stack */
struct stack *createStack()
{
	struct stack *s = new stack();
	s->count = 0;
	return s;
}

// Function to push an element to the stack
void push(struct stack *s, int data)
{
	// create a new node
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = s->head;
	s->count += 1;
   
	if(s->count == 1)
		s->middle = temp;
	
	else
	{
		s->head->prev = temp;
		if(s->count & 1)
			s->middle = s->middle->prev;
	}

	s->head = temp;
}
int pop(struct stack *s)
{
	if(!s->count)  
	{
		return -1;
	}
	struct node *temp = s->head;
	int item = temp->data;
	s->head = temp->next;
	
	if(s->head)
		s->head->prev = NULL;
	
	
	s->count -= 1;
	if(!((s->count) & 1))
		s->middle = s->middle->next;
		
	free(temp);
	return item;
}

int getMiddleEle(struct stack *s)
{
	
	return !(s->count)? -1: s->middle->data; 
}

int deleteMiddleEle(struct stack *s)
{
	if(s->count > 0)
	{
		struct node* temp = s->middle;
		int data = temp->data;
	
		s->middle = (s->count &1)? temp->next: temp->prev;
		
		s->count -= 1;

		if(temp->prev)
			temp->prev->next = temp->next;
		if(temp->next)
			temp->next->prev = temp->prev;
		free(temp);
		
		if(s->count == 0)
		{
			s->head = NULL;
			s->middle = NULL;
			
		}
		return data;
	}
	else
	{
		
		return -1;
	}
}

int main()
{
	struct stack *s = createStack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	push(s, 40);
	push(s, 50);
	push(s, 60);
	push(s, 70);
	cout<<getMiddleEle(s)<<endl;
	pop(s);
	pop(s);
	cout<<getMiddleEle(s)<<endl;
	cout<<deleteMiddleEle(s);
	return 0;
}