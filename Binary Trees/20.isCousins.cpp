#include <bits/stdc++.h>
using namespace std;
class Node
{
  public:
    int data;
    Node *right;
    Node *left;
}*root=NULL;
Node *createNode(int k)
{
    Node *curr=new Node();
    curr->data=k;
    curr->left=NULL;
    curr->right=NULL;
    return curr;
}
int findLevel(Node *root,int a,int level)
{
    int count;
    if(root==NULL)
       return -1;
    if(root->data==a)
       return level;
    int left=findLevel(root->left,a,level+1);
    if(left!=-1)
       return left;
    return findLevel(root->right,a,level+1);
}
int isSibling(Node *root,int a,int b)
{
    if(root==NULL)
       return 0;
    if(root->left && root->right)
       return (root->left->data==a && root->right->data==b 
            || root->right->data==a && root->left->data==b
            || isSibling(root->left,a,b) 
            || isSibling(root->right,a,b));
    return 0;
}
bool isCousins(Node *root,int a,int b)
{
    int levelA=findLevel(root,a,0);
    int levelB=findLevel(root,b,0);
    cout<<levelA<<endl;
    cout<<levelB<<endl;
    if(levelB!=levelA)
    {
        return false;
    }
    else
    {
      return !isSibling(root,a,b);
    }
}
int main()
{
    root=createNode(6);
    root->left=createNode(3);
    root->right=createNode(5);
    root->left->left=createNode(7);
    root->left->right=createNode(8);
    root->right->left=createNode(1);
    root->right->right=createNode(2);
    cout<<isCousins(root,7,3);
    
}
