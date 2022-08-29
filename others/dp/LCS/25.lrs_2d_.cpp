// A dynamic programming based C program to
// find length of the shortest supersequence
#include <bits/stdc++.h>
using namespace std;
string lrs(string X, string Y, int m, int n)
{
    string lcs[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
               lcs[i][j]="";
            else if(X[i-1]==Y[j-1] && j!=i)
               lcs[i][j]=lcs[i-1][j-1]+X[i-1];
            else
               lcs[i][j]=lcs[i-1][j].size() > lcs[i][j-1].size() ? lcs[i-1][j] : lcs[i][j-1];
        }
    }
    return lcs[m][n];
}

int main()
{
	string X = "AABEBCDD";
	int n=X.length();
	cout<< lrs(X, X,n,n);
	return 0;
}
