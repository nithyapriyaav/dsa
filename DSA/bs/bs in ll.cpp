// Iterative C++ program to search
// an element in linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};
Node *newNode(int x)
{
    struct Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}
 
Node *middle(Node *start,Node *last)
{
    if(start==NULL)
       return NULL;
    Node *slow=start,*fast=start;
    while(fast!=last && fast->next!=last)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
bool search(Node* head, int x)
{
	Node *start=head;
	Node *last=NULL;
	while(last==NULL || last!=start)
	{
	    Node *mid=middle(start,last);
	    if(mid==NULL)
	       return NULL;
	    if(mid->data==x)
	       return mid;
	    else if(mid->data<x)
	       start=mid->next;
	    else
	       last=mid;
	}
	return NULL;
}

int main()
{
    Node *head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(7);
    head->next->next->next = newNode(8);
    head->next->next->next->next = newNode(9);
    head->next->next->next->next->next = newNode(10);
    int value = 101;
    if (search(head, value))
        printf("present\n");
    else
        printf("Not Present");
    return 0;
}
