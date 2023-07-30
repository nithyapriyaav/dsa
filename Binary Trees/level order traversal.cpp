/* C++ program to print level
	order traversal using STL */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
	int data;
	struct Node *left, *right;
};

void printLevelOrder(Node *root)
{
    if(root==NULL) 
       return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left)
           q.push(curr->left);
        if(curr->right)
           q.push(curr->right);
    }
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int countNodes(Node* root)
{
    if(root==NULL)
       return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}
int count2Nodes(Node* root)
{
    int count=0;
    if(root==NULL)
       return 0;
    if(root->left && root->right)
       count++;
    if(root->left)
       count+=count2Nodes(root->left);
    if(root->right)
       count+=count2Nodes(root->right);
    return count;
}
int height(Node *root)
{
    if(root==NULL)
       return 0;
    return 1+max(height(root->left),height(root->right));
}
int diameter(Node *root)
{
    if(root==NULL)
       return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
    int ldia=diameter(root->left);
    int rdia=diameter(root->right);
    return max(lheight+rheight+1,max(ldia,rdia));
}
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
// 	root->right->left = newNode(6);
// 	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	cout<<endl;
	cout<<countNodes(root)<<endl;
	cout<<count2Nodes(root)<<endl;
	cout<<diameter(root)<<endl;
	return 0;
}
