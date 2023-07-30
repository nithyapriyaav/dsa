#include <bits/stdc++.h>
using namespace std;
int CountSubsetSum(vector<int> set,int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(set[i-1]>j)
               dp[i][j]=dp[i-1][j];
            else
               dp[i][j]= dp[i-1][j] || dp[i-1][j-set[i-1]];
        }
    }
    int ans=INT_MAX;
    for(int j=0;j<=sum/2;j++)
    {
        int first=j;
        int second=sum-j;
        if(dp[n][j]==1)
            ans=min(ans,abs(second-first));
    }       
    return ans;
}
int main()
{
	vector<int> set = { 2,4,2,6};
	int sum=accumulate(set.begin(),set.end(),0);
	int n = set.size();
	cout<<CountSubsetSum(set, n, sum);
	return 0;
}
