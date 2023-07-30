#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// numbers with only 3 distinct factors -- prime+perfect square
string func(int n)
{
    int x=sqrt(n);
    if(x*x==n)
    {
        int count=0;
        for(int i=2;i<sqrt(x);i++)
        {
            if(i%n==0)
               return "no";
        }
        return "yes";
    }
    else
       return "no";
 
}
string factors(int n)
{
    int count=2;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
           count=count+2;
    }
    if(count==3)
        return "yes";
    else
       return "no";
 
}
int main()
{
    int n=121;
    cout<< func(n)<<endl;
    cout<< factors(n);
}