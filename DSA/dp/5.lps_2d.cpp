#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
int max(int x,int y)
{
    return x>y?x:y;
}
int lps(char *str)
{
    int n=strlen(str);
    int i,j,col;
    int lps[n][n];
    for(int i=0;i<n;i++)
       lps[i][i]=1;
    for(col=1;col<n;col++)
    {
        for(i=0;i<n-col;i++)
        {
            j=i+col;
            if(str[i]==str[j] && col==1)
                lps[i][j]=2;
            else if(str[i]==str[j])
                lps[i][j]=lps[i+1][j-1]+2;
            else
                lps[i][j]=max(lps[i+1][j],lps[i][j-1]);
        }
    }
    return lps[0][n-1];
}

int main()
{
	char seq[] = "GEEKSFORGEEKS";
	int n = strlen(seq);
	printf ("The length of the LPS is %d", lps(seq));
	getchar();
	return 0;
}




#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int max(int x,int y)
{
    return x>y?x:y;
}
string lps(string str)
{
    int n=str.size();
    int i,j,col;
    string lps[n][n];
    for(int i=0;i<n;i++)
       lps[i][i]=str[i];
    for(col=1;col<n;col++)
    {
        for(i=0;i<n-col;i++)
        {
            j=i+col;
            if(str[i]==str[j] && col==1)
                lps[i][j]=str[i]+str[j];
            else if(str[i]==str[j])
                lps[i][j]=str[j]+lps[i+1][j-1]+str[i];
            else
                lps[i][j]=lps[i+1][j].size() > lps[i][j-1].size() ? lps[i+1][j] : lps[i][j-1];
        }
    }
    return lps[0][n-1];
}

int main()
{
	string seq= "GEEKETSFORGEEKS";
	int n = seq.size();
	cout<< "The length of the LPS is "<< lps(seq);
	getchar();
	return 0;
}
