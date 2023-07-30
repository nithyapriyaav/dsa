#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *left;
  node *right;
};
queue<node*> q;
node* createNode(int ele)
{
    node *new1=new node();
    new1->data=ele;
    new1->left=NULL;
    new1->right=NULL;
    return new1;
}
// level order insertion
void insert(int ele)
{
    node *root=q.front();
    node *new2=createNode(ele);
    if(root==NULL)
    {
        root=new2;
    }
    else if(root->left==NULL)
    {
        root->left=new2;
    }
    else
    {
        root->right=new2;
        q.pop();
    }
    q.push(new2);
}
int countNodes(node *root)
{
    if(root==NULL)
       return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int Count2child(node *root)
{
    if(root==NULL)
       return 0;
    int sum=0;
    if(root->left && root->right)
       sum++;
    sum+=Count2child(root->left)+Count2child(root->right);
    return sum;
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int height(node *root)
{
    
    if(root==NULL)
       return 0;
    return 1+max(height(root->left),height(root->right));
}
int main()
{
    node *root=NULL;
    int n;
    cin>>n;
    int ele;
    cin>>ele;
    root=createNode(ele);
    q.push(root);
    for(int i=1;i<n;i++)
    {
        cin>>ele;
        insert(ele);
    }
    inorder(root);
    cout<<"\n";
    cout<< countNodes(root);
    cout<<"\n";
    cout<< height(root);
    cout<<"\n";
    cout<< Count2child(root);
}