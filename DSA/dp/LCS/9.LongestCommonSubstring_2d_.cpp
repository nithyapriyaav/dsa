#include <bits/stdc++.h>
using namespace std;

string lcs(char *X, char *Y, int m, int n)
{
    string lcs[m+1][n+1];
    string ans="";
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1] && j!=1 && i!=1)
            {
                lcs[i][j]=lcs[i-1][j-1]+X[i-1];
                ans=ans.size()>lcs[i][j].size()?ans : lcs[i][j];
            }
            else
               lcs[i][j]="";
        }
    }
    return ans;
}
// Driver program to test above function
int main()
{

	char X[] = "AGGTABA";
	char Y[] = "GXGTABAXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of LCS is: " << lcs(X, Y, m, n);

	return 0;
}




/* Dynamic Programming C implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m, int n)
{
    int lcs[m+1][n+1];
    int ans=0;
    memset(lcs,0,sizeof(lcs));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1] && j!=1 && i!=1)
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
                ans=max(lcs[i][j],ans);
            }
            else
               lcs[i][j]=0;
        }
    }
    return ans;
}
// Driver program to test above function
int main()
{

	char X[] = "AGGTABA";
	char Y[] = "GXGTABAXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of LCS is: " << lcs(X, Y, m, n);

	return 0;
}
// code submitted by Aditya Yadav (adityayadav012552)
