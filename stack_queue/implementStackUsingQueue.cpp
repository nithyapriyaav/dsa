//costly push
/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack {
	queue<int> q1, q2;
public:
	void push(int ele)
	{
	    q2.push(ele);
	    while(!q1.empty())
	    {
	        q2.push(q1.front());
	        q1.pop();
	    }
	    queue<int> temp=q1;
	    q1=q2;
	    q2=temp;
	}
	int pop()
	{
	    int x=-1;
	    if(!q1.empty())
	    {
	        x=q1.front();
	        q1.pop();
	    }
	    return x;
	}
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
}


// costly pop
#include <bits/stdc++.h>

using namespace std;

class Stack {
	queue<int> q1, q2;
public:
	void push(int ele)
	{
	    q1.push(ele);
	}
	int pop()
	{
	    while(q1.size()>1)
	    {
	        q2.push(q1.front());
	        q1.pop();
	    }
	    int x=q1.front();
	    queue<int> temp=q1;
	    q1=q2;
	    q2=temp;
	    return x;
	}
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
}

// single queue
/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack {
	queue<int> q1;
public:
	void push(int ele)
	{
	    int size=q1.size();
	    q1.push(ele);
	    while(size--)
	    {
	        q1.push(q1.front());
	        q1.pop();
	    }
	}
	int pop()
	{
	    int x=-1;
	    if(!q1.empty())
	    {
	        x=q1.front();
	        q1.pop();
	    }
	    return x;
	}
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
}
// This code is contributed by Chhavi

