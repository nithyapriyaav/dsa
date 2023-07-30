#include <bits/stdc++.h>
using namespace std;
double multiply(double mid,int n)
{
    double pro=1;
    for(int i=0;i<n;i++)
    {
        pro=pro*mid;
    }
    return pro;
}
void getNthRoot(double m, int n)
{
    // edge cases
    double low,high;
    if(m>=0 && m<=1)
    {
        low=m;
        high=1;
    }
    else
    {
        low=1;
        high=m;
    }
    
    // 0.000001=1e-6
    double eps=1e-6;
    
    while(high-low>eps)
    {
        double mid=(high+low)/2;
        if(multiply(mid,n)<m)
          low=mid;
        else
          high=mid;
    }
    cout<< fixed << setprecision(16) << low << " " <<high << endl;
    
    //to check
    cout<< pow(m,1/(double)n);
}

int main()
{
    double m;
    int n;
    cin>>m>>n;
    getNthRoot(m, n);
    return 0;
}