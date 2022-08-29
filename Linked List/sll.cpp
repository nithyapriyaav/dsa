// You are using GCC
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
       int data;
       Node *next;
}*head=NULL;
void create(int a[],int n)
{
    Node *neww,*last;
    for(int i=0;i<n;i++)
    {
        neww=new Node();
        neww->data=a[i];
        neww->next=NULL;
        if(head==NULL)
        {
            head=neww;
            last=neww;
        }
        else
        {
            last->next=neww;
            last=neww;
        }
    }
}
void insert(Node **head,int key)
{
    Node *neww=new Node();
    neww->data=key;
    neww->next=(*head);
    *head=neww;
}
void insertBack(Node *head,int key)
{
    Node *ptr=head;
    Node *neww=new Node();
    neww->data=key;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=neww;
    neww->next=NULL;
}
void middle(Node *head,int key,int pos)
{
    Node *neww=new Node();
    neww->data=key;
    Node *ptr=head;
    int i=1;
    while(i<pos-1 && ptr->next!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    neww->next=ptr->next;
    ptr->next=neww;
}
void display(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    create(a,n);
    insert(&head,23);
    middle(head,11,4);
    insertBack(head,2555);
    display(head);
    cout<<"\n"<<head->data;
}