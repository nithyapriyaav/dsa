#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
      int data;
      Node *next;
}*head=NULL;
void insert(int arr[],int n)
{
    Node *last,*newNode;
    for(int i=0;i<n;i++)
    {
        newNode=new Node();
        newNode->data=arr[i];
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            last=head;
        }
        else
        {
            last->next=newNode;
            last=last->next;
        }
    }
}
Node* clone()
{
    Node *ptr=head;
    Node *head1=NULL,*last=NULL;
    while(ptr!=NULL)
    {
        Node *newNode=new Node();
        newNode->data=ptr->data;
        newNode->next=NULL;
        if(head1==NULL)
        {
            head1=newNode;
            last=head1;
        }
        else
        {
            last->next=newNode;
            last=last->next;
        }
        ptr=ptr->next;
    }
    return head1;
}
void display(Node *head1)
{
    Node *ptr=head1;
    while(ptr!=NULL)
    {
        cout<< ptr->data <<" ";
        ptr=ptr->next;
    }
}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    insert(arr,n);
    Node *head1=clone();
    display(head1);
}