// C++ Program to Implement a Phone
// Directory Using Trie Data Structure
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	unordered_map<char,TrieNode*> child;
	bool isLast;
	TrieNode()
	{
		for (char i = 'a'; i <= 'z'; i++)
			child[i] = NULL;

		isLast = false;
	}
};
TrieNode *root = NULL;
void insert(string s)
{
	int len = s.length();
	TrieNode *itr = root;
	for (int i = 0; i < len; i++)
	{
		if(itr->child[s[i]]==NULL)
        {
			itr->child[s[i]]= new TrieNode();
		}
		itr=itr->child[s[i]];
		if (i == len - 1)
			itr->isLast = true;
	}
}
void displayContactsUtil(TrieNode *curNode, string prefix)
{
	if (curNode->isLast)
		cout << prefix << endl;
	for (char i = 'a'; i <= 'z'; i++)
	{
		if (curNode->child[i] != NULL)
			displayContactsUtil(curNode->child[i], prefix + (char)i);
	}
}
void displayContacts(string str)
{
	TrieNode *curr = root;

	string prefix = "";
	int len = str.length();
	int i;
	for (i=0; i<len; i++)
	{
		prefix += (char)str[i];
		char lastChar = prefix[i];
		if (curr->child[lastChar] == NULL)
		{
			cout << "No Results Found for " << prefix<< "\n";
			i++;
			break;
		}

		cout << "Suggestions based on " << prefix<<": ";
		displayContactsUtil(curr->child[lastChar], prefix);

		curr=curr->child[lastChar];
	}

	for (; i<len; i++)
	{
		prefix += (char)str[i];
		cout << "No Results Found for " << prefix<< "\n";
	}
}

void insertIntoTrie(string contacts[],int n)
{
	root = new TrieNode();
	for (int i = 0; i < n; i++)
		insert(contacts[i]);
}
int main()
{
	string contacts[] = {"gforgeeks" , "geeksquiz"};
	int n = sizeof(contacts)/sizeof(string);
	insertIntoTrie(contacts, n);

	string query = "gekk";

	// Note that the user will enter 'g' then 'e', so
	// first display all the strings with prefix as 'g'
	// and then all the strings with prefix as 'ge'
	displayContacts(query);

	return 0;
}
