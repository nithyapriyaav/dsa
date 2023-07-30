// CPP program to implement Queue using
// two stacks with costly enQueue()
#include <bits/stdc++.h>
using namespace std;

struct Queue 
{
	stack<int> s1, s2;

	void enQueue(int x)
	{
	    while(!s1.empty())
	    {
	        s2.push(s1.top());
	        s1.pop();
	    }
	    s1.push(x);
	    while(!s2.empty())
	    {
	        s1.push(s2.top());
	        s2.pop();
	    }
	}

	int deQueue()
	{
	    int x= s1.top();
	    s1.pop();
	    return x;
	}
};

int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

	return 0;
}


// CPP program to implement Queue using
// two stacks with costly deQueue()
#include <bits/stdc++.h>
using namespace std;

struct Queue 
{
	stack<int> s1, s2;

	void enQueue(int x)
	{
	    s1.push(x);
	}

	int deQueue()
	{
	    if (s2.empty()) 
	    {
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
	    int x=s2.top();
	    s2.pop();
	    return x;
	}
};

int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

	return 0;
}
