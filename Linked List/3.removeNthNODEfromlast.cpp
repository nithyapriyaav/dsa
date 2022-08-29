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
Node *getNode(int key)
{
    Node *ptr=head;
    while(ptr->data!=key) 
       ptr=ptr->next;
    return ptr;
}
void removeNode(int index)
{
    Node *ptr=head;
    int len=0;
    while(ptr!=NULL)
    {
        len++;
        ptr=ptr->next;
    }
    int n=len-index-1;
    ptr=head;
    while(n--)
    {
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
}
int main()
{
    int n=5;
    int i;
    int a[n]={1,2,3,4,5};
    create(a,n);
    display(head);
    cout<<endl;
    removeNode(4);
    display(head);
}







// 2 ptr approach
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
Node *getNode(int key)
{
    Node *ptr=head;
    while(ptr->data!=key) 
       ptr=ptr->next;
    return ptr;
}
void removeNode(int index)
{
    Node *slow=head;
    Node *fast=head;
    while(index--)
        fast=fast->next;
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
}
int main()
{
    int n=5;
    int i;
    int a[n]={1,2,3,4,5};
    create(a,n);
    display(head);
    cout<<endl;
    removeNode(2);
    display(head);
}