// C++ program for flattening a Linked List
// pq
#include <bits/stdc++.h>
using namespace std;

// Link list node
class Node {
public:
	int data;
	Node *right, *down;
};

Node* head = NULL;
struct compare
{
    bool operator()(Node *a,Node *b)
    {
       return a->data>b->data;
    }
};
void flatten(Node* head)
{
    priority_queue<Node*,vector<Node*>,compare> pq;
    while(head!=NULL)
    {
        pq.push(head);
        head=head->right;
    }
    while(!pq.empty())
    {
        Node *curr=pq.top();
        pq.pop();
        cout<<curr->data<<" ";
        if(curr->down)
           pq.push(curr->down);
    }
}
Node* push(Node* head_ref, int data)
{

	// Allocate the Node & Put in the data
	Node* new_node = new Node();

	new_node->data = data;
	new_node->right = NULL;

	// Make next of new Node as head
	new_node->down = head_ref;

	// Move the head to point to new Node
	head_ref = new_node;

	return head_ref;
}

void printList()
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->down;
	}
	cout << endl;
}

// Driver's code
int main()
{

	/* Let us create the following linked list
		5 -> 10 -> 19 -> 28
		| |	 |	 |
		V V	 V	 V
		7 20 22 35
		|		 |	 |
		V		 V	 V
		8		 50 40
		|			 |
		V			 V
		30			 45
	*/
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);

	head->right = push(head->right, 20);
	head->right = push(head->right, 10);

	head->right->right = push(head->right->right, 50);
	head->right->right = push(head->right->right, 22);
	head->right->right = push(head->right->right, 19);

	head->right->right->right
		= push(head->right->right->right, 45);
	head->right->right->right
		= push(head->right->right->right, 40);
	head->right->right->right
		= push(head->right->right->right, 35);
	head->right->right->right
		= push(head->right->right->right, 20);

	flatten(head);

// 	printList();
	return 0;
}



// merge from last
#include <bits/stdc++.h>
using namespace std;

// Linked list Node
struct Node {
	int data;
	struct Node* next;
	struct Node* bottom;

	Node(int x)
	{
		data = x;
		next = NULL;
		bottom = NULL;
	}
};
Node *merge(Node* a,Node *b)
{
    Node *head=new Node(0);
    Node *curr=head;
    while(a!=NULL && b!=NULL)
    {
        if(a->data<b->data)
        {
            curr->bottom=a;
            a=a->bottom;
        }
        else
        {
            curr->bottom=b;
            b=b->bottom;
        }
        curr=curr->bottom;
    }
    while(a)
    {
        curr->bottom=a;
        a=a->bottom;
        curr=curr->bottom;
    }
    while(b)
    {
        curr->bottom=b;
        b=b->bottom;
        curr=curr->bottom;
    }
    return head->bottom;
}
Node* flatten(Node* root)
{
    if(root==NULL || root->next==NULL)
       return root;
    root->next=flatten(root->next);
    
    root=merge(root,root->next);
    return root;
}
void printList(Node *head)
{
    while(head->bottom!=NULL)
    {
        cout<<head->data<<"->";
        head=head->bottom;
    }
    cout<<head->data;
}
int main(void)
{
	Node* head = new Node(5);
	auto temp = head;
	auto bt = head;
	bt->bottom = new Node(7);
	bt->bottom->bottom = new Node(8);
	bt->bottom->bottom->bottom = new Node(30);
	temp->next = new Node(10);

	temp = temp->next;
	bt = temp;
	bt->bottom = new Node(20);
	temp->next = new Node(19);
	temp = temp->next;
	bt = temp;
	bt->bottom = new Node(22);
	bt->bottom->bottom = new Node(50);
	temp->next = new Node(28);
	temp = temp->next;
	bt = temp;
	bt->bottom = new Node(35);
	bt->bottom->bottom = new Node(40);
	bt->bottom->bottom->bottom = new Node(45);
	head=flatten(head);
	printList(head);
	cout << endl;
	return 0;
}
// this code is contributed by user_990i
