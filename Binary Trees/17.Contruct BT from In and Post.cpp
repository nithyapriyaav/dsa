#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
struct Node* buildTree(int in[],int post[],int start,int end,unordered_map<int,int> mp)
{
    static int postorder=end;
    if(start>end)
       return NULL;
    int ch=post[postorder--];
    struct Node* root=newNode(ch);
    if(start==end)
       return root;
    
    int index=mp[ch];
    
    root->right=buildTree(in,post,index+1,end,mp);
    root->left=buildTree(in,post,start,index-1,mp);
    return root;
}
struct Node* build(int in[],int post[],int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[in[i]]=i;
    }
    return buildTree(in,post,0,n-1,mp);
}
void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;
	
	printf("%d ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

/* Driver program to test above functions */
int main()
{
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
	int len = sizeof(in) / sizeof(in[0]);

	struct Node* root = build(in, post, len);

	/* Let us test the built tree by printing
	Inorder traversal */
	printf("Inorder traversal of the constructed tree is \n");
	printPreorder(root);
}
