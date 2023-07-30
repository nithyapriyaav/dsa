
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

void printTopView(Node* root)
{
    if(root==NULL )
       return;
	queue<pair<Node*,int>> q;
	map<int,int> mp;
	q.push({root,0});
	while(!q.empty())
	{
	    auto it=q.front();
	    q.pop();
	    Node *curr=it.first;
	    int line=it.second;
	    if(mp.find(line)==mp.end())
	       mp[line]=curr->data;
	    if(curr->left)
	       q.push({curr->left,line-1});
	    if(curr->right)
	       q.push({curr->right,line+1});
	}
	for(auto it:mp)
	{
	    cout<< it.second<<" ";
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

	printTopView(root);
}

// This code is contributed by
// Manne SreeCharan
