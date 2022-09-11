// C++ program for Quick Sort on Singly Linked List

#include <cstdio>
#include <iostream>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}
struct Node* getTail(struct Node* cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}
struct Node* partition(struct Node* head, struct Node* tail)
{
    // 1st ele as pivot
    struct Node* pivot=head;  // pivot=low 
    struct Node *curr=head->next,*prev=head;
    // for(int i=low,j=low+1;j<=high;j++)
    while(curr!=tail->next)
    {
        if(pivot->data>curr->data)   // if(a[pivot]>a[j])
        {
            swap(prev->next->data,curr->data);   // swap(a[i+1],a[j])
            prev=prev->next;   // i+=1
        }
        curr=curr->next;
    }
    swap(prev->data,pivot->data);  // swap(a[pivot],a[i]);
    return prev;   // return pivot;
}
void sortList(struct Node* head,struct Node* tail)
{
	if(head==NULL || tail==NULL || head==tail)
	   return;
	// l<r
	struct Node* pivot=partition(head,tail);
	sortList(head,pivot);
	sortList(pivot->next,tail);
}
void quickSort(struct Node** headRef)
{
    struct Node* head=*headRef;
    // already sorted
	if(head==NULL || head->next==NULL)
	   return;
	struct Node* tail=getTail(head);
	sortList(head,tail);
}
int main()
{
	struct Node* a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);
	cout << "Linked List before sorting \n";
	printList(a);
	quickSort(&a);
	cout << "Linked List after sorting \n";
	printList(a);

	return 0;
}
