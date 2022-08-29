// using pq
/* C++ program to merge two sorted linked lists */
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
	Node()
	{
	    this->data=0;
	    this->next=NULL;
	}
	Node(int key)
	{
	    this->data=key;
	    this->next=NULL;
	}
};

/* pull off the front node of
the source and put it in dest */
void MoveNode(Node** destRef, Node** sourceRef);

/* Takes two lists sorted in increasing
order, and splices their nodes together
to make one big sorted list which
is returned. */
Node* SortedMerge(Node* a, Node* b)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    while(a!=NULL)
    {
        pq.push(a->data);
        a=a->next;
    }
    while(b!=NULL)
    {
        pq.push(b->data);
        b=b->next;
    }
    Node *ptr=new Node(0);
    Node *curr=ptr;
    while(!pq.empty())
    {
        int ele=pq.top();
        pq.pop();
        curr->next=new Node(ele);
        curr=curr->next;
    }
    return ptr->next;
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the
node from the front of the source,
and move it to the front of the dest.
It is an error to call this with the
source list empty.

Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}

After calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(Node** destRef, Node** sourceRef)
{
	/* the front source node */
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new node */
	newNode->next = *destRef;

	/* Move dest to point to the new node */
	*destRef = newNode;
}


/* Function to insert a node at
the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;

	/* Let us create two sorted linked lists
	to test the functions
	Created lists, a: 5->10->15, b: 2->3->20 */
	push(&a, 15);
	push(&a, 111);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	/* Remove duplicates from linked list */
	res = SortedMerge(a, b);

	cout << "Merged Linked List is: \n";
	printList(res);

	return 0;
}

// This code is contributed by rathbhupendra















//  merge then sort
/* C++ program to merge two sorted linked lists */
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node
{
	public:
	int data;
	Node* next;
	Node()
	{
	    this->data=0;
	    this->next=NULL;
	}
	Node(int key)
	{
	    this->data=key;
	    this->next=NULL;
	}
};

/* pull off the front Node of
the source and put it in dest */
void MoveNode(Node** destRef, Node** sourceRef);

/* Takes two lists sorted in increasing
order, and splices their Nodes together
to make one big sorted list which
is returned. */
Node* mergelists(Node** head1,
                 Node** head2)
{
    Node *curr=*head1;
    while(curr!=NULL)
    {
        if(head2!=NULL && curr->next==NULL)
        {
            curr->next=*head2;
            break;
        }
        curr=curr->next;
    }
    return *head1;
}
 
// Sort the linked list using bubble sort
void sortlist(Node** head1)
{
    Node* curr = *head1;
    Node* temp = *head1;
 
    // Compares two adjacent elements
    // and swaps if the first element
    // is greater than the other one.
    while (curr->next != NULL) {
 
        temp = curr->next;
        while (temp != NULL) {
 
            if (temp->data < curr->data) {
                int t = temp->data;
                temp->data = curr->data;
                curr->data = t;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}
/* UTILITY FUNCTIONS */
/* MoveNode() function takes the
Node from the front of the source,
and move it to the front of the dest.
It is an error to call this with the
source list empty.

Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}

After calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(Node** destRef, Node** sourceRef)
{
	/* the front source Node */
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new Node */
	newNode->next = *destRef;

	/* Move dest to point to the new Node */
	*destRef = newNode;
}


/* Function to insert a Node at
the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate Node */
	Node* new_Node = new Node();

	/* put in the data */
	new_Node->data = new_data;

	/* link the old list off the new Node */
	new_Node->next = (*head_ref);

	/* move the head to point to the new Node */
	(*head_ref) = new_Node;
}

/* Function to print Nodes in a given linked list */
void printList(Node *Node)
{
	while (Node!=NULL)
	{
		cout<<Node->data<<" ";
		Node = Node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;

	/* Let us create two sorted linked lists
	to test the functions
	Created lists, a: 5->10->15, b: 2->3->20 */
	push(&a, 15);
	push(&a, 111);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	/* Remove duplicates from linked list */
	res = mergelists(&a, &b);
	sortlist(&res);
	cout << "Merged Linked List is: \n";
	printList(res);

	return 0;
}

// This code is contributed by rathbhupendra
