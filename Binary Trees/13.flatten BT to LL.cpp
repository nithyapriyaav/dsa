// C++ Program to flatten a given Binary Tree into linked
// list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

// utility that allocates a new Node with the given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

// Function to convert binary tree into linked list by
// altering the right node and making left node point to
// NULL
void flatten(struct Node* root)
{
	if(root==NULL || root->left==NULL && root->right==NULL)
	   return;
	if(root->left!=NULL)
	{
	    flatten(root->left);
	    Node* ptr=root->right;
	    root->right=root->left;
	    root->left=NULL;
	    
	    Node* t=root->right;
	    while(t->right!=NULL)
	        t=t->right;
	    t->right=ptr;
	}
	flatten(root->right);
}

// To find the inorder traversal
void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

/* Driver program to test above functions*/
int main()
{
	/* 1
		/ \
	2	 5
	/ \	 \
	3 4	 6 */
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->right = newNode(6);
	flatten(root);
	cout << "The Inorder traversal after flattening binary tree ";
	inorder(root);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
