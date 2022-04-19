// Find middle of the linked List
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

ListNode* getMiddel(ListNode* head){
    if(!head and !head->next){
        return head;
    }
    ListNode* temp = head;
    ListNode* middle = NULL;
    int count =0;
    while(temp){
        count++;
        temp = temp->next;
    }
    temp = head;
    if(count%2==0){
        count = count/2 +1;
        while(--count){
            temp = temp->next;
        }
        middle = temp;
    }
    
    else{
        temp = head;
        count = count/2;
        while(count--){
            temp = temp->next;
        }
        middle = temp;
    }
    return middle;
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
    ListNode* middleNode = getMiddel(List1);
    cout<<endl;
    cout<<middleNode->data;
    
    
}