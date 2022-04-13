// Intersection of Two Linked Lists
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int d) {
        data = d;
        next = NULL;
    }
};

void insertion_at_Tail(ListNode* &head1, int data) {
    if (head1 == NULL) {
        ListNode* node = new ListNode(data);
        head1 = node;
        return;
    }
    ListNode* temp = head1;
    ListNode* node = new ListNode(data);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}
ListNode *find_intersection(ListNode *head1, ListNode *head2){
    int c1=0,c2=0,diff=0;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        while(temp1!=NULL){
            c1++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            c2++;
            temp2 = temp2->next;
        }
        

        diff  = abs(c1-c2);

        if(c1>c2){
            while(diff--){
                head1 = head1->next;
            }
        }
        else{
            while(diff--){
                head2 = head2->next;
            }
        }
        

        while(head1!=NULL and head2!=NULL){
            if(head1 == head2){
                return head1;
            }
             head1 = head1->next;
             head2 = head2->next;
        }
        return NULL;
}

int main(){
    ListNode* head1 = NULL,*head2=NULL;
    insertion_at_Tail(head1,1);
    insertion_at_Tail(head1,2);
    insertion_at_Tail(head1,3);
    insertion_at_Tail(head1,4);
    insertion_at_Tail(head1,5);
    insertion_at_Tail(head1,6);
    insertion_at_Tail(head2,12);
    ListNode*temp = head1;
    temp = temp->next;
    head2= temp;
    cout<<find_intersection(head1,head2);//it will return address of intersectin point
    return 0;
}