
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

void bottomView(Node* root)
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


    Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}

// This code is contributed by
// Manne SreeCharan
