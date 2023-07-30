// CPP program to check for balanced brackets.
#include <bits/stdc++.h>
#include<string>
using namespace std;
bool areBracketsBalanced(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(st.empty())
            st.push(s[i]);
        else if((st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']') || (st.top()=='(' && s[i]==')'))
            st.pop();
        else
            st.push(s[i]);
    }
    if(st.empty())
       return true;
    return false;
}
int main()
{
	string expr = "]{}(){}[]";

	if (areBracketsBalanced(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}



// or
// CPP program to check for balanced brackets.
#include <bits/stdc++.h>
using namespace std;
bool areBracketsBalanced(string s)
{
   stack<char> st;
    for(auto i:s)
    {
        if(i=='{' || i=='[' || i=='(')
             st.push(i);
        else
        {
            if(st.empty() || (st.top()=='{' && i!='}') || (st.top()=='[' && i!=']') || (st.top()=='(' && i!=')'))
                return false;
            st.pop();
        }
    }
    if(st.empty())
       return true;
    return false;
}
int main()
{
	string expr = "{}(){}[]";

	if (areBracketsBalanced(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}
