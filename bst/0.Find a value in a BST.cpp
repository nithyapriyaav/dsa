#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *left;
  node *right;
};
node* createNode(int ele)
{
    node *new1=new node();
    new1->data=ele;
    new1->left=NULL;
    new1->right=NULL;
    return new1;
}
node* Insert(node *root,int key)
{
    if(root==NULL)
    {
        node *curr=createNode(key);
        return curr;
    }
    if(root->data>key)
       root->left=Insert(root->left,key);
    if(root->data<key)
       root->right=Insert(root->right,key);
    return root;
}
bool search(struct node* root, int x) {
    if(root==NULL || root->data==x)
       return root;
    else if(root->data>x)
       return search(root->left,x);
    else if(root->data<x)
       return search(root->right,x);
    return NULL;
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
int main()
{
    node *root = NULL;
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 10);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);
 
    inorder(root);
    if(search(root,40))
       cout<< "yes";
    else
       cout<< "no";
    return 0;
}