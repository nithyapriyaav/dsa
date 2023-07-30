// Recursive optimized C program to find the diameter of a
// Binary Tree
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct node {
	int data;
	struct node *left, *right;
};
int height(struct node* root,int &ans)
{
    if(root==NULL)
       return 0;
    int lheight=height(root->left,ans);
    int rheight=height(root->right,ans);
    ans=max(ans,lheight+rheight+1);  //based on nodes
    return 1+max(lheight,rheight);
}
int diameter(struct node* root)
{
    if(root==NULL)
       return 0;
    int ans=0;
    height(root,ans);
    return ans;
}
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Driver Code
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// Function Call
	cout << "Diameter of the given binary tree is " <<
		diameter(root);

	return 0;
}















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
int height(Node *root,int &ans)
{
    // ans- to update the diameter
    if(root==NULL)
      return 0;
    int lheight=height(root->left,ans);
    int rheight=height(root->right,ans);
    ans=max(ans,lheight+rheight+1);
    return max(lheight,rheight)+1;
}
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	cout<<endl;
	int ans=0;
	cout<<height(root->left,ans)<<endl;  // prints height
	cout<<ans<<endl;  // prints diameter
	return 0;
}
