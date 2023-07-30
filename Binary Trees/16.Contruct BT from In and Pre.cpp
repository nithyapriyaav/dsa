/* C++ program to construct tree using inorder
and preorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};
struct Node* newNode(char data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
struct Node* buildTree(char in[],char pre[],int start,int end,unordered_map<char,int> mp)
{
    static int preorder=0;
    if(start>end)
       return NULL;
    char ch=pre[preorder++];
    struct Node* root=newNode(ch);
    if(start==end)
       return root;
    
    int index=mp[ch];
    
    root->left=buildTree(in,pre,start,index-1,mp);
    root->right=buildTree(in,pre,index+1,end,mp);
    return root;
}
struct Node* Inorder(char in[],char pre[],int n)
{
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[in[i]]=i;
    }
    return buildTree(in,pre,0,n-1,mp);
}
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%c ", node->data);
	printInorder(node->right);
}

/* Driver program to test above functions */
int main()
{
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int len = sizeof(in) / sizeof(in[0]);

	struct Node* root = Inorder(in, pre, len);

	/* Let us test the built tree by printing
	Inorder traversal */
	printf("Inorder traversal of the constructed tree is \n");
	printInorder(root);
}
