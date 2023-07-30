/* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	struct Node *left, *right;
	int data;
};

// Utility function to create a new tree Node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
struct Node *findLCA(struct Node* root, int n1, int n2)
{
    //base case
    if(root==NULL || root->data==n1 || root->data==n2)
       return root;
    Node* left=findLCA(root->left,n1,n2);
    Node* right=findLCA(root->right,n1,n2);
    //result
    if(left==NULL)
       return right;
    else if(right==NULL)
       return left;
    else
       return root;
}
int main()
{
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
	cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
	cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
	cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
