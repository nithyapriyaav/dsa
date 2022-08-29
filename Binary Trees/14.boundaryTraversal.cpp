
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
void printBoundary(Node* root)
{
	queue<Node*> q;
	q.push(root);
	vector<int> res;
	while(!q.empty())
	{
	    int size=q.size();
	    for(int i=0;i<size;i++)
	    {
	        Node *neww=q.front();
	        q.pop();
	        if(i==0)
	           cout<< neww->data<<" ";
	        if(i==size-1) 
	           res.push_back(neww->data);
	        if(neww->left) 
	            q.push(neww->left);
	        if(neww->right) 
	            q.push(neww->right); 
	    }
	}
	reverse(res.begin(),res.end());
	for(int i=0;i<res.size()-1;i++)
	{
	    cout<< res[i] <<" ";
	}
}	

// Driver code
int main()
{
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    printBoundary(root);
 
}

// This code is contributed by
// Manne SreeCharan
