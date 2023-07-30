#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


bool isSymmetric(node * root,node *root1) 
{
   if(root==NULL || root1==NULL)
      return true;
   if(root && root1 && root->data==root1->data)
      return isSymmetric(root->left,root1->right) 
             && isSymmetric(root->right,root1->left);
   return false;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> right = newNode(4);
  root -> right = newNode(2);
  root -> right -> left = newNode(4);
  root -> right -> right = newNode(3);

  bool res;
  res = isSymmetric(root,root);

  if (res)
    cout << "The tree is symmetrical";
  else cout << "The tree is NOT symmetrical";

  return 0;
}
