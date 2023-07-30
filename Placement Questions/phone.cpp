#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool check(string s1,string s2,int m,int n)
{
    int res=0;
    int i=0,j=0;
    if(abs(m-n)>1)
          return false;
    while(i<m && j<n)
    {
        if(s1[i]!=s2[j])
        {
            if(res==1)
              return false;
            if(m>n)
               i++;
            else if(m<n)
               j++;
            else
            {
                i++;
                j++;
            }
            res++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if(i<m || j<n)
    {
        res++;
    }
    return res==1 || res==0;
}
int main()
{
    string s1="pale";
    string s2="pale";
    int m=s1.length();
    int n=s2.length();
    if(check(s1,s2,m,n))
       cout<< "True";
    else
       cout<< "False";
    return 0;
}









