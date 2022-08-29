#include <bits/stdc++.h>
using namespace std;
int isSubsetSum(vector<int> set,int n,int sum)
{
    if(sum & 1)
       return 0;
    int dp[n+1][sum/2+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=sum/2;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum/2;j++)
        {
            if(set[i-1]>j)
               dp[i][j]=dp[i-1][j];
            else
               dp[i][j]= dp[i-1][j] || dp[i-1][ j-set[i-1] ];
        }
    }
    return dp[n][sum/2];
}
int main()
{
	vector<int> set = { 2,3,4,4,5,2, 3 };
	int sum = accumulate(set.begin(),set.end(),0);
	cout<< sum<<endl;
	int n = set.size();
	if (isSubsetSum(set, n, sum))
		cout <<"Equal partition subset sum";
	else
		cout <<"No equal partition";
	return 0;
}



#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(vector<int> set,int n,int sum)
{
    if(sum & 1)
       return 0;
    bool dp[n+1][sum/2+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=false;
    for(int i=1;i<=sum/2;i++)
        dp[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum/2;j++)
        {
            if(set[i-1]>j)
               dp[i][j]=dp[i-1][j];
            else if(set[i-1]==j)
               dp[i][j]=true;
            else
               dp[i][j]= dp[i-1][j] || dp[i-1][ j-set[i-1] ];
        }
    }
    return dp[n][sum/2];
}
int main()
{
	vector<int> set = { 2,3,4,4,5,2,1 ,1};
	int sum = accumulate(set.begin(),set.end(),0);
	cout<< sum<<endl;
	int n = set.size();
	if (isSubsetSum(set, n, sum))
		cout <<"Equal partition subset sum";
	else
		cout <<"No equal partition";
	return 0;
}


