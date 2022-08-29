#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int precedence(char ch)
{
    if(ch=='^')
       return 3;
    else if(ch=='*' || ch=='/' || ch=='%')
       return 2;
    else if(ch=='+' || ch=='-')
       return 1;
    return -1;
}
string inTOpost(string s)
{
    stack<char> st;
    string res="";
    for(auto i:s)
    {
        // cout<<i<<endl;
        if(i>='A' && i<='Z')
           res+=i;
        else if(i>='a' && i<='z')
           res+=i;
        else if(i=='(') 
           st.push(i);
        else if(i==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && precedence(st.top())>=precedence(i))
            {
                res+=st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}
int main()
{
    // string infix="((a+(b*c))-d)";
    string infix="a+b*(c^d-e)^(f+g*h)-i";
    string postfix=inTOpost(infix);
    cout<< postfix;
    return 0;
    // Postfix is : abc*+d-
    // abcd^e-fgh*+^*+i-
}
