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
ListNode* divide(ListNode* &head){
    ListNode* p,*sec; 
    p = head->next->next;
    while(p){
        p = p->next;
        head = head->next;
        if(p){
            p = p->next;
        }
    }
    sec = head->next;
    head->next = NULL;
    return sec;
}
ListNode* merge(ListNode* &head1,ListNode* &head2){
    ListNode* temp,*mergeList;
    if(head1==NULL){
      mergeList = head2;
    }
    if(head2==NULL){
      mergeList = head1;
    }
    if(head1->data<=head2->data){
        mergeList = head1;
        head1 = head1->next;
    }
    else{
        mergeList = head2;
        head2 = head2->next;
    }
    temp = mergeList;
    while(head1 and head2){
        if(head1->data <= head2->data) {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }    
    }
    temp->next = (!head1)?head2:head1;
    return mergeList;
}
ListNode*mergeSort(ListNode* &head){
    ListNode* first,*second,*mereged;
    if(head and head->next){
        first = head;
        second = divide(head);
        first = mergeSort(first);
        second = mergeSort(second);
        mereged = merge(first,second);
        return mereged;
    }
    else{
        return head;
    }
}
ListNode* getIntersection(ListNode* &head1,ListNode* &head2){
        ListNode* inetersectionList = NULL;
        
        while(head1 and head2){
            if(head1->data==head2->data){
                inetersectionList = insert(inetersectionList,head1->data);
                head1 = head1->next;
                head2 = head2->next;
            }
            else{
                if(head1->data<head2->data){
                    head1 = head1->next;
                }
                else{
                    head2 = head2 ->next;
                }
            }

        }
        return inetersectionList;
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
ListNode* getUnion(ListNode* &head1,ListNode* &head2){
    ListNode* UnionList = NULL;
    int new_ele;
    while(head1 and head2){
        if(head1->data==head2->data){
            new_ele = head1->data;
            head1 = head1->next;
            head2 = head2->next;
        }
        else{
            if(head1->data<head2->data){
                new_ele = head1->data;
                head1 = head1->next;
            }
            else{
                new_ele = head2->data;
                head2 = head2->next;
            }

        }
        UnionList = insert(UnionList,new_ele);
    }
    for(;head1;head1 =head1->next){
        UnionList = insert(UnionList,head1->data);
    }
    for(;head2;head2 =head2->next){
        UnionList = insert(UnionList,head2->data);
    }
    return UnionList;
}
int main(){

    ListNode* List1 =NULL;
    List1 = insert(List1,10);
    List1 = insert(List1,30);
    List1 = insert(List1,20);
    List1 = insert(List1,40);
    List1 = insert(List1,60);
    List1 = insert(List1,70);
    List1 = mergeSort(List1);
    ListNode* List2 =NULL;
    List2 = insert(List2,10);
    List2 = insert(List2,30);
    List2 = insert(List2,40);
    List2 = insert(List2,80);
    List2 = insert(List2,60);
    List2 = insert(List2,70);
    List2 = mergeSort(List2);

    ListNode* inetersectionList = getIntersection(List1,List2);
    printList(inetersectionList);
    cout<<endl;
    ListNode * unionList = getUnion(List1,List2);
    printList(unionList);
    return 0;
}