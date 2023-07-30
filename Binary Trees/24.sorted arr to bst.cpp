// C++ program to print BST in given range
#include<bits/stdc++.h>
using namespace std;

/* A Binary Tree node */
class Node
{
	public:
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data);

Node* sortedArrayToBST(int arr[],
						int start, int end)
{
    Node *root  =NULL;
    if(start>end)
       return root;
    int mid=(start+end)/2;
    root=newNode(arr[mid]);
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);
    return root;
}

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* A utility function to print
preorder traversal of BST */
void InOrder(Node* node)
{
	if (node == NULL)
		return;
	InOrder(node->left);
	cout << node->data << " ";
	
	InOrder(node->right);
}

// Driver Code
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Convert List to BST */
	Node *root = sortedArrayToBST(arr, 0, n-1);
	cout << "PreOrder Traversal of constructed BST \n";
	InOrder(root);

	return 0;
}

// This code is contributed by rathbhupendra
