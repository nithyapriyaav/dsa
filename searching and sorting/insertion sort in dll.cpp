// C++ implementation for insertion Sort on a doubly linked list
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* prev, *next;
};
struct Node* getNode(int data)
{
	struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

// function to insert a new node in sorted way in
// a sorted doubly linked list
void sortedInsert(struct Node** head_ref, struct Node* newNode)
{
	struct Node* current;

	// if list is empty
	if (*head_ref == NULL)
		*head_ref = newNode;

	// if the node is to be inserted at the beginning
	// of the doubly linked list
	else if ((*head_ref)->data >= newNode->data) {
		newNode->next = *head_ref;
		newNode->next->prev = newNode;
		*head_ref = newNode;
	}

	else {
		current = *head_ref;

		// locate the node after which the new node
		// is to be inserted
		while (current->next != NULL &&
			current->next->data < newNode->data)
			current = current->next;

		/*Make the appropriate links */

		newNode->next = current->next;

		// if the new node is not inserted
		// at the end of the list
		if (current->next != NULL)
			newNode->next->prev = newNode;

		current->next = newNode;
		newNode->prev = current;
	}
}

// function to sort a doubly linked list using insertion sort
void insertionSort(struct Node* head)
{
    struct Node *curr=head,*temp;
    while(curr->next!=NULL)
    {
        temp=curr->next;
        while(temp!=NULL)
        {
            if(curr->data>temp->data)
            {
                int ele=temp->data;
                temp->data=curr->data;
                curr->data=ele;
            }
            temp=temp->next;
        }
        curr=curr->next;
    }
    
}

// function to print the doubly linked list
void printList(struct Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

// Driver program to test above
int main()
{
	/* start with the empty doubly linked list */
	struct Node* head = NULL;

	// insert the following data
	push(&head, 9);
	push(&head, 3);
	push(&head, 5);
	push(&head, 10);
	push(&head, 12);
	push(&head, 8);

	cout << "Doubly Linked List Before Sorting\n";
	printList(head);

	insertionSort(head);
	cout<<"\n";
	cout << "Doubly Linked List After Sorting\n";
	printList(head);

	return 0;
}
