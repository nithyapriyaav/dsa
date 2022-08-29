#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;
};
Node* createNode(int ele)
{
    Node *new1=new Node();
    new1->data=ele;
    new1->left=NULL;
    new1->right=NULL;
    return new1;
}
Node* Insert(Node *root,int key)
{
    if(root==NULL)
    {
        Node *curr=createNode(key);
        return curr;
    }
    if(root->data>key)
       root->left=Insert(root->left,key);
    if(root->data<key)
       root->right=Insert(root->right,key);
    return root;
}
int minValue(struct Node *root) {
    if(root==NULL)
      return -1;
    if(root->left==NULL)
      return root->data;
    return minValue(root->left);
    // if(root==NULL) 
    //     return -1;
    // while(root->left!=NULL)
    //     root=root->left;
    // return root->data;
}
int maxValue(struct Node *root) {
    if(root==NULL)
      return -1;
    if(root->right==NULL)
      return root->data;
    return maxValue(root->right);
}
void inorder(Node *root)
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
    Node *root = NULL;
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 100);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);
 
    inorder(root);
    cout<<endl;
    cout<< minValue(root);
    cout<<endl;
    cout<< maxValue(root);
  
    return 0;
}