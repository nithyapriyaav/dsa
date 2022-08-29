#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
      int data;
      Node *prev;
      Node *next;
}*head=NULL;
void insert(int arr[],int n)
{
    Node *last,*newNode;
    for(int i=0;i<n;i++)
    {
        newNode=new Node();
        newNode->data=arr[i];
        newNode->prev=NULL;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            last=head;
        }
        else
        {
            newNode->prev=last;
            last->next=newNode;
            last=last->next;
        }
    }
}
void reverse()
{
    Node *curr=head,*temp;
    while(curr!=NULL)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;

        curr=curr->prev;
    }
    if(temp!=NULL)
    {
        head=temp->prev;
    }
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
    int arr[]={1,2,3,4,5,6,7,8};
    int n=8;
    insert(arr,n);
    reverse();
    display();
}