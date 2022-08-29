// C++ program to implement a stack that supports
// getMinimum() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;
struct MyStack
{
	stack<int> s;
	int mini;
	void push(int data)
	{
	    cout<< "Number inserted: ";
	    if(s.empty())
	    {
	        s.push(data);
	        mini=data;
	    }
	    else if(data<mini)
	    {
	            int ele=2*data-mini;
	            s.push(ele);
	            mini=data;
	   }
	   else
	   {
	       s.push(data);
	   }
	   cout<< data<<endl;
	   
	}
	void getMin()
	{
	    if(s.empty())
	        cout<< "stack is empty"<<endl;
	    else
	        cout<< "Min element is: "<<mini<<endl;
	}
	void peek()
	{
	    if(s.empty())
	        cout<< "stack is empty"<<endl;
	    else
	    {
	        int x=s.top();
	        if(x<mini)
	            cout<< "Top element is:"<<mini<<endl;
	        else
	            cout<< "Top element is:"<<x<<endl;

	    }
	}
	void pop()
	{
	    if(s.empty())
	       cout<< "stack is empty"<<endl;
	    else
	    {
	        cout<< "Top element removed: ";
	        int x=s.top();
	        s.pop();
	        if(x<mini)
	        {
	            cout<<mini<<endl;
	            mini=2*mini - x;
	        }
	        else
	           cout<<x<<endl;
	    }
	}
};

int main()
{
	MyStack s;
	s.push(3);
	s.push(5);
	s.getMin();
	s.push(2);
	s.push(1);
	s.getMin();
	s.pop();
	s.getMin();
	s.pop();
	s.peek();
	s.getMin();

	return 0;
}
