#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
    public:
    class Node 
    {
        public:
      int key;
      int val;
      Node *next;
      Node *prev;
      Node(int _key,int _value)
      {
          key=_key;
          val=_value;
//           next=NULL;
//           prev=NULL;
      }
    };
    
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;
    
     LRUCache(int capacity)
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node *newNode)
    {
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
        
    }
    void deleteNode(Node *ptr)
    {
        Node *nprev=ptr->prev;
        Node *nnext=ptr->next;
        nprev->next=nnext;
        nnext->prev=nprev;       
    }
  

    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            Node *curr=mp[key];
            int ele=curr->val;
            mp.erase(key);
            deleteNode(curr);
            addNode(curr);
            mp[key]=head->next;
            return ele;
        }
        return -1;
        
    }

  void put(int key_, int value) {
    if (mp.find(key_) != mp.end()) {
      Node * existingnode = mp[key_];
      mp.erase(key_);
      deleteNode(existingnode);
    }
    if (mp.size() == cap) {
      mp.erase(tail -> prev -> key);
      deleteNode(tail -> prev);
    }

    addNode(new Node(key_, value));
    mp[key_] = head -> next;
  }
};
