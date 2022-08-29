/* C++ program to print level
	order traversal using STL */
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

void zigzag(Node *root)
{
    if(root==NULL) 
       return;
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> v;
    int flag=true;
    while(!q.empty())
    {
        vector<int> res;
        int size=q.size();
        while(size--)
        {
            Node *curr=q.front();
            q.pop();
            res.push_back(curr->data);
            if(curr->left)
               q.push(curr->left);
            if(curr->right)
               q.push(curr->right);
        }
        flag=!flag;
        if(flag)
           reverse(res.begin(),res.end());
        v.push_back(res); 
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
            cout<< v[i][j]<< " ";
    }
}

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	zigzag(root);
	return 0;
}
