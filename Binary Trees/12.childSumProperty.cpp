/* Program to check children sum property */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, left
child and right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* returns 1 if children sum property holds
for the given node and both of its children*/
int isSumProperty(struct node* node)
{
    int sum=0;
	if(node==NULL || node->left==NULL && node->right==NULL) 
	   return 1;
	if(node->left)
	   sum+=node->left->data;
	if(node->right)
	   sum+=node->right->data;
	return (node->data==sum) && isSumProperty(node->left) && isSumProperty(node->right);
}

struct node* newNode(int data)
{
	struct node* node =
		(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

// Driver Code
int main()
{
	struct node *root = newNode(10);
	root->left	 = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->right = newNode(2);
	if(isSumProperty(root))
		cout << "The given tree satisfies "
			<< "the children sum property ";
	else
		cout << "The given tree does not satisfy "
			<< "the children sum property ";

	getchar();
	return 0;
}
// This code is contributed by Akanksha Rai
