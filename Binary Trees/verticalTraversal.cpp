// C++ program for printing vertical
// order of a given binary tree using BFS
#include <bits/stdc++.h>

using namespace std;

// Structure for a binary tree node
struct Node {
	int data;
	Node *left, *right;
};

// A function to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// The main function to print vertical
// order of a binary tree with given root
void printVerticalOrder(Node* root)
{
    if(root==NULL) 
       return;
    // q - node,{line,level}
    // mp-line,level,elements with duplicates
    queue<pair<Node*,pair<int,int>>> q;
    map<int,map<int,multiset<int>>> mp;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        Node* root=it.first;
        int x=it.second.first;
        int y=it.second.second;
        mp[x][y].insert(root->data);
        if(root->left)
           q.push({root->left,{x-1,y+1}});
        if(root->right)
           q.push({root->right,{x+1,y+1}});
    }
    vector<vector<int>> res;
    for(auto i:mp)
    {
        vector<int> col;
        for(auto j:i.second)
        {
            col.insert(col.end(),j.second.begin(),j.second.end());
        }
        res.push_back(col);
    }
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
           cout<<res[i][j]<< " ";
        cout<<endl;
    }
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left = newNode(10);
	root->right->right->left->right = newNode(11);
	root->right->right->left->right->right = newNode(12);
	cout << "Vertical order traversal is \n";
	printVerticalOrder(root);
	return 0;
}
