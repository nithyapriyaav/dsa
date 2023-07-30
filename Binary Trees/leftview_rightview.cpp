// C++ program to print left view of
// Binary Tree

#include<bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// function to print left view of
// binary tree
void printLeftView(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
	    int size=q.size();
	    for(int i=0;i<size;i++)
	    {
	        Node *neww=q.front();
	        q.pop();
	        if(i==size-1)
	           cout<< neww->data<<" ";
	        if(neww->left) 
	            q.push(neww->left);
	        if(neww->right) 
	            q.push(neww->right); 
	    }
	}
}	

// Driver code
int main()
{
	// Let's construct the tree as
	// shown in example

	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printLeftView(root);
}

// This code is contributed by
// Manne SreeCharan
