#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
        }
};
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}
node* reverseKNodes(node* head,int k) 
{
    node *prev=NULL,*next=NULL;
    node *curr=head;
    int count=0;
    while(count<k && curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    // calls function even 1 node is present
    // if(curr!=NULL)
    //     head->next=reverseKNodes(curr,k);
    if(next!=NULL)
        head->next=reverseKNodes(next,k);
    return prev;
}

void printLinkedList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<"\n";
}

int main() {
    node* head = NULL;
    int k = 4;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);
    insertNode(head,7);
    insertNode(head,8);
    
    cout<<"Original Linked List: "; printLinkedList(head);
    cout<<"After Reversal of k nodes: "; 
    node* newHead = reverseKNodes(head,k);
    printLinkedList(newHead);
    
    return 0;
}