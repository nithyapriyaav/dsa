#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
int max(int x,int y)
{
    return x>y?x:y;
}
void printSubStr(char *str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        printf("%c",str[i]);
}
int lps(char *str)
{
    int start=0;
    int n=strlen(str);
    int i,j,col;
    int lps[n][n];
    int maxLength=1;
    
    memset(lps,0,sizeof(lps));
    for(int i=0;i<n;i++)
       lps[i][i]=1;
    
    // check for sub-string of length 2
    for(int i=0;i<n-1;i++)
    {
        if(str[i]==str[i+1])
        {
            lps[i][i+1]=1;
            maxLength=2;
            start=i;
        }
    }
    
    for(col=2;col<n;col++)
    {
        for(i=0;i<n-col;i++)
        {
            j=i+col;
            if(str[i]==str[j] && lps[i+1][j-1])
            {
                lps[i][j]=1;
                if(col>maxLength)
                {
                    maxLength=col;
                    start=i;
                }
            }
            
        }
    }
    printSubStr(str,start,start+maxLength);
    printf("\n");
    return maxLength+1;
}

int main()
{
	char seq[] = "forgeeksskeegfor";
	int n = strlen(seq);
	printf ("The length of the LPS is %d", lps(seq));
	getchar();
	return 0;
}
