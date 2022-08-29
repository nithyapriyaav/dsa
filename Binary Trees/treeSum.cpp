/* C++ program to print level
	order traversal using STL */
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};
int sum(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return root->data + sum(root->left) + sum(root->right);
}
void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
int main()
{
	Node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	inorder(root);
	cout<<endl;
	cout<< sum(root);
	return 0;
}
