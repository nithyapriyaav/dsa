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
               dp[i][j]= dp[i-1][j] + dp[i-1][j-set[i-1]];
        }
    }
    return dp[n][sum];
}
int main()
{
	vector<int> set = { 1,2,3,3};
	int diff=3;
	int sum=accumulate(set.begin(),set.end(),0);
	int n = set.size();
	int s1=(diff+sum)/2;
	cout<<CountSubsetSum(set, n, s1);
	return 0;
}
