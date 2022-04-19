#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int d){
        data = d;
        next = NULL;
    }
};
ListNode* insert(ListNode* &head,int data){
    ListNode *node = new ListNode(data);
    node->data = data;
    node->next = head;
    return node;

}

void printList(ListNode* &head){
    ListNode* temp =head;
    cout<<"List :";
    while (temp)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    
}
ListNode*swap_pair(ListNode* &List){
    if(!List or !List->next){
        return List;
    }
    ListNode* temp = new ListNode(NULL);
    ListNode* prev  = temp;
    ListNode* curr = List;
    while(curr and curr->next){
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;
        prev = curr;
        curr = curr->next;
        
    }
    return temp->next;
}
int main(){

    ListNode* List1 =NULL;
    List1 = insert(List1,10);
    List1 = insert(List1,30);
    List1 = insert(List1,20);
    List1 = insert(List1,40);
    List1 = insert(List1,60);
    List1 = insert(List1,70);
    printList(List1);
    ListNode* List2 = swap_pair(List1);
    cout<<endl;
    printList(List2);
    
}