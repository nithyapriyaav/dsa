// C++ program to count number of nodes
// in loop in a linked list if loop is
// present
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};
int countNodes(struct Node *slow)
{
    int i=1;
    struct Node *ptr=slow;
    while(ptr->next!=slow)
    {
        i++;
        ptr=ptr->next;
    }
    return i;
}
int countNodesinLoop(struct Node *list)
{
    struct Node *slow=list,*fast=list;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
           return countNodes(slow);
    }
    return 0;
}

struct Node *newNode(int key)
{
	struct Node *temp =
(struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// Driver Code
int main()
{
	struct Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next;

	cout << countNodesinLoop(head) << endl;

	return 0;
}
