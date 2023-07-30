/* LCS string */
#include <bits/stdc++.h>
using namespace std;

string lcs(char *X, char *Y, int m, int n)
{
    string lcs[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
               lcs[i][j]="";
            else if(X[i-1]==Y[j-1])
               lcs[i][j]=lcs[i-1][j-1]+X[i-1];
            else
               lcs[i][j]=lcs[i-1][j].size() > lcs[i][j-1].size() ? lcs[i-1][j] : lcs[i][j-1];
        }
    }
    return lcs[m][n];
}

// Driver program to test above function
int main()
{

	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of LCS is: " << lcs(X, Y, m, n);

	return 0;
}


/* Dynamic Programming C implementation of LCS problem length */
#include <bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m, int n)
{
    int lcs[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
               lcs[i][j]=0;
            else if(X[i-1]==Y[j-1])
               lcs[i][j]=lcs[i-1][j-1]+1;
            else
               lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[m][n];
}

// Driver program to test above function
int main()
{

	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of LCS is: " << lcs(X, Y, m, n);

	return 0;
}

