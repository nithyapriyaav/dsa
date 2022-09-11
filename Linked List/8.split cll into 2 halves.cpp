// CLL
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
       int data;
       Node *next;
}*head=NULL,*tail=NULL;
void create(int a[],int n)
{
    Node *neww;
    for(int i=0;i<n;i++)
    {
        neww=new Node();
        neww->data=a[i];
        neww->next=NULL;
        if(head==NULL)
        {
            head=neww;
            tail=neww;
            tail->next=head;  // size is 1
        }
        else
        {
            tail->next=neww;
            tail=neww;
            tail->next=head;
        }
    }
}
void display(Node *root)
{
    Node *head=root;
    while(head->next!=root)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data<<" ";
}
void split(Node *head, Node** head1, Node** head2)
{
    // size is 1
    if(head->next==tail)
    {
        *head1=head;
        return;
    }
    Node *slow=head,*fast=head;
    // odd size=fast->next is head
    // even size=fast->next->next is head
    while(fast->next!=head && fast->next->next!=head)
    {
        slow=slow->next;  //mid
        fast=fast->next->next;
    }
    if(fast->next->next==head)
        fast=fast->next;
    *head1=head;
    *head2=slow->next;
    slow->next=*head1;
    fast->next=*head2;
}
int main()
{
    int i,n=1;
    int a[n]={4};
    create(a,n);
    display(head);
    
    Node *head1=NULL,*head2=NULL;
    split(head,&head1,&head2);
    cout<<endl;
    display(head1);
    cout<<endl;
    display(head2);
}