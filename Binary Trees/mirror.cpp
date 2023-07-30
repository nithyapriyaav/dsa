/* C++ program to print level
	order traversal using STL */
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};
Node* mirror(Node *root)
{
    if(root==NULL)
        return root;
    mirror(root->left);
    mirror(root->right);
    Node *temp=root->right;
    root->right=root->left;
    root->left=temp;
    // swap(root->left,root->right);
    return root;
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
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	inorder(root);
	cout<<endl;
	mirror(root);
	inorder(root);
	return 0;
}
