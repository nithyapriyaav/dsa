// A dynamic programming based C program to
// find length of the shortest supersequence
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int superSeq(char *X, char *Y, int m, int n)
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

int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m=strlen(X);
	int n=strlen(Y);
	cout << "Length of the shortest supersequence is "
		<< m+n-superSeq(X, Y,m,n);
	return 0;
}



// string
// A dynamic programming based C program to
// find length of the shortest supersequence
#include <bits/stdc++.h>
using namespace std;
string superSeq(string X, string Y, int m, int n)
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

int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	int m=X.length();
	int n=Y.length();
	string Z=superSeq(X, Y,m,n);
	int j=0,k=0;
	for(auto ch:Z)
	{
	    while(j<m && X[j]!=ch)
	    {
	        cout<<X[j];
	        j++;
	    }
	    while(k<n && Y[k]!=ch)
	    {
	        cout<<Y[k];
	        k++;
	    }
	    cout<<ch;
	    j++;
	    k++;
	}
	return 0;
}
