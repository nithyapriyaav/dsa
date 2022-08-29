#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
int evaluatePostfix(char* exp)
{
    int i=0;
    stack<int> s;
    int res;
    while(exp[i]!='\0')
    {
        // cout<<exp[i]<<endl;
        if(exp[i]>='0' && exp[i]<='9')
        {
            s.push(exp[i]-'0');  // store int not char
            i++;
        }
        else
        {
            int ch2=s.top();  // top is B
            s.pop();
            int ch1=s.top();  // next top is A
            s.pop();
            switch(exp[i])
            {
                case '+': res=ch1+ch2;
                          s.push(res);
                          break;
                case '-': res=ch1-ch2;
                          s.push(res);
                          break;
                case '*': res=ch1*ch2;
                          s.push(res);
                          break;
                case '/': res=ch1/ch2;
                          s.push(res);
                          break;
                case '%': res=ch1%ch2;
                          s.push(res);
                          break;
            }
            i++;
        }
    }
    return s.top();
}
int main()
{
	char exp[] = "231*+9-";
	cout<<"postfix evaluation: "<< evaluatePostfix(exp);
	//postfix evaluation: -4
	return 0;
}
