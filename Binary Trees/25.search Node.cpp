bool search(Node *root,int key)
{
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    bool temp=search(root->left,key);
    if(temp==true)
       return temp;
    return search(root->right,key);
    
}