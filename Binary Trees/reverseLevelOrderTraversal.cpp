/* C++ program to print level
	order traversal using STL */
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

void reverseLevelOrder(Node *root)
{
    if(root==NULL) 
       return;
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> v;
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
        v.push_back(res); 
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
            cout<< v[i][j]<< " ";
        cout<<endl;
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
	Node* root = newNode(11);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	reverseLevelOrder(root);
	return 0;
}
