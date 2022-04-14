
#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	Node *next,*random;
	Node(int x)
	{
		data = x;
		next = random = NULL;
	}
};


void print(Node *start)
{
	Node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random = "
			<< ptr->random->data << endl;
		ptr = ptr->next;
	}
}

Node* clone(Node *start)
{
	Node* curr = start,*temp;
    while(curr){
        temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
	curr = start;

	while (curr)
	{
		if(curr->next){
           curr->next->random = curr->random?curr->random->next:curr->random;
        }
        curr = curr->next?curr->next->next:curr->next;
	}

	Node* original = start,*copy = start->next;
    temp = copy;
    while (original and copy)
    {
        original->next = original->next?original->next->next:original->next;
        copy->next = copy->next?copy->next->next:copy->next;
        original = original->next;
        copy = copy->next;
    }
    

	return temp;
}

Node* clone_1(Node *head)
{
	map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->data);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
}

int main()
{
	Node* start = new Node(1);
	start->next = new Node(2);
	start->next->next = new Node(3);
	start->next->next->next = new Node(4);
	start->next->next->next->next = new Node(5);
	start->random = start->next->next;
	start->next->random = start;
	start->next->next->random =
					start->next->next->next->next;
	start->next->next->next->random =
					start->next->next->next->next;
	start->next->next->next->next->random =
									start->next;
	cout << "Original list : \n";
	print(start);
	cout << "\nCloned list : \n";
	Node *cloned_list = clone(start);
    print(cloned_list);
    cout << "\nCloned list : \n";
	Node *cloned_list_1= clone_1(start);
	print(cloned_list_1);

	return 0;
}
