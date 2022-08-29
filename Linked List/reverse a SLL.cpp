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
void reverse()
{
    Node *prev=NULL;
    Node *next=NULL,*curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
void display()
{
    Node *ptr=head;
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
    reverse();
    display();
}