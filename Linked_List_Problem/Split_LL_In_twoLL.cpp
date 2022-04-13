#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
	int data;
	struct Node* next;
};


void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d —> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}


void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}


void moveNode(struct Node** destRef, struct Node** sourceRef)
{

	if (*sourceRef == NULL) {
		return;
	}

	struct Node* newNode = *sourceRef;  
	*sourceRef = (*sourceRef)->next;	
	newNode->next = *destRef;   		
	*destRef = newNode; 				
}


void alternatingSplit(struct Node* source, struct Node** aRef, struct Node** bRef)
{
	
	struct Node* a = NULL;
	struct Node* b = NULL;

	struct Node* current = source;

	while (current != NULL)
	{
		moveNode(&a, &current); 		

		if (current != NULL) {
			moveNode(&b, &current); 	
		}
	}

	*aRef = a;
	*bRef = b;
}

int main(void)
{
	
	int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(keys)/sizeof(keys[0]);

	
	struct Node* head = NULL;
	for (int i = n-1; i >= 0; i--) {
		push(&head, keys[i]);
	}

	struct Node *a = NULL, *b = NULL;
	alternatingSplit(head, &a, &b);


	printf("First List: ");
	printList(a);

	printf("Second List: ");
	printList(b);

	return 0;
}