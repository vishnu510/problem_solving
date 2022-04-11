#include<iostream>
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;
    ListNode(int d) {
        data = d;
        next = NULL;
    }
};

void insertion_at_Tail(ListNode*& head, int data) {
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
void print_ll(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
/*bool find_loop(ListNode* &head){
    if(!head){
        return false;
    }
    ListNode *slow =head;
    ListNode *fast =head;
    while(slow->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}*/
int main(){

    ListNode* head = NULL;
    insertion_at_Tail(head, 1);
    insertion_at_Tail(head, 2);
    insertion_at_Tail(head, 3);
    insertion_at_Tail(head, 4);
    insertion_at_Tail(head, 5);
    insertion_at_Tail(head, 6);
    insertion_at_Tail(head, 7);
    insertion_at_Tail(head, 8);
    insertion_at_Tail(head, 9);

    //cout<<find_loop(head);
    print_ll(head);

    return 0;
}