// easy approach
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int k)
{
	struct Node* node = new Node;
	node->data = k;
	node->right = node->left = NULL;
	return node;
}
bool isHeap(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr=q.front();
        q.pop();
        if(curr->left)
        {
            if(curr->left->data > curr->data)
                return false;
            q.push(curr->left);
        }
        else
           return true;
        if(curr->right)
        {
            if(curr->right->data > curr->data)
                return false;
            q.push(curr->right);
        }
        else
           return true;
    }
    return true;
}
int main()
{
	struct Node* root = NULL;
	root = newNode(100);
	root->left = newNode(19);
	root->right = newNode(18);
	root->left->left = newNode(17);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	root->left->left->left = newNode(3);
	root->left->left->right = newNode(2);
	root->left->right->left = newNode(1);

	// Function call
	if (isHeap(root))
		cout << "Given binary tree is a Heap\n";
	else
		cout << "Given binary tree is not a Heap\n";

	return 0;
}



// C++ program to checks if a
// binary tree is max heap or not
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int k)
{
	struct Node* node = new Node;
	node->data = k;
	node->right = node->left = NULL;
	return node;
}
bool isHeap(Node* root)
{
    queue<Node*> q;
    q.push(root);
    bool temp=false;
    while(!q.empty())
    {
        Node *curr=q.front();
        q.pop();
        if(curr->left)
        {
            if(temp || curr->left->data > curr->data)
                return false;
            q.push(curr->left);
        }
        else
            temp=true;
        if(curr->right)
        {
            if(temp || curr->right->data > curr->data)
                return false;
            q.push(curr->right);
        }
        else
            temp=true;
    }
    return true;
}
int main()
{
	struct Node* root = NULL;
	root = newNode(10);
	root->left = newNode(9);
	root->right = newNode(8);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	root->left->left->left = newNode(3);
	root->left->left->right = newNode(2);
	root->left->right->left = newNode(1);

	// Function call
	if (isHeap(root))
		cout << "Given binary tree is a Heap\n";
	else
		cout << "Given binary tree is not a Heap\n";

	return 0;
}
