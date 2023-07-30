#include <bits/stdc++.h>
using namespace std;

string isSeq(char *X, char *Y, int m, int n)
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

	char X[] = "AXYQ";
	char Y[] = "ADXCPY";

	int m = strlen(X);
	int n = strlen(Y);

    if(isSeq(X, Y, m, n).size()==m)
       cout<< "yes";
    else
       cout<< "No";

	return 0;
}

















#include <bits/stdc++.h>
using namespace std;

bool isSeq(char *X, char *Y, int m, int n)
{
    int j=0;
    for(int i=0;i<n && j<m;i++)
    {
        if(X[j]==Y[i]) 
           j++;
    }
    return j==m;
}

// Driver program to test above function
int main()
{

	char X[] = "AXYA";
	char Y[] = "ADXCPYA";

	int m = strlen(X);
	int n = strlen(Y);

    if(isSeq(X, Y, m, n))
       cout<< "yes";
    else
       cout<< "No";

	return 0;
}