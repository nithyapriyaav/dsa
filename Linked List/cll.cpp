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
    
    display(head);
  
}