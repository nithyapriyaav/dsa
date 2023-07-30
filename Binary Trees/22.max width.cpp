// without null
#include <bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		this->data = d;
		this->left = this->right = NULL;
	}
};
int getMaxWidth(node *root)
{
    if(root==NULL)
       return 0;
    queue<node*> q;
    q.push(root);
    int count=0;
    while(!q.empty())
    {
        int size=q.size();
        count=max(count,size);
        for(int i=0;i<size;i++)
        {
            node *curr=q.front();
            q.pop();
            if(curr->left)
               q.push(curr->left);
            if(curr->right)
               q.push(curr->right);
        }
    }
    return count;
    
}
int main()
{
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(8);
	root->right->right->left = new node(6);
	root->right->right->right = new node(7);

	cout << "Maximum width is " << getMaxWidth(root)
		<< endl;
	return 0;
}

















// with null
#include <bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		this->data = d;
		this->left = this->right = NULL;
	}
};
int getMaxWidth(node *root)
{
    if(root==NULL)
       return 0;
    queue<pair<node*,int>> q;
    q.push({root,0});
    int count=0;
    int leftNode,rightNode;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            
            node* curr=q.front().first;
            int id=q.front().second;
            q.pop();
            
            if(i==0) 
               leftNode=id;
            if(i==size-1)
               rightNode=id;
            if(curr->left)
               q.push({curr->left,2*id+1});
            if(curr->right)
               q.push({curr->right,2*id+2});
        }
        count=max(count,rightNode-leftNode+1);
    }
    return count;
    
}
int main()
{
    node * root = new node(1);
    root -> left = new node(3);
    root -> left -> left = new node(5);
    root -> left -> left -> left = new node(7);
  root -> right = new node(2);
  root -> right -> right = new node(4);
  root -> right -> right -> right = new node(6);

	cout << "Maximum width is " << getMaxWidth(root)
		<< endl;
	return 0;
}
