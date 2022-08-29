// 2d array
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
	int sum=6;
	int n = set.size();
	cout<<CountSubsetSum(set, n, sum);
	return 0;
}









// two 1d arrays

#include <bits/stdc++.h>
using namespace std;
int CountSubsetSum(vector<int> set,int n,int sum)
{
    vector<int> dp(sum+1);
    vector<int> prev(sum+1);
    dp[0]=1;
    for(int i=1;i<=sum;i++)
        dp[i]=0;
    prev=dp;
    for(int i=1;i<=n;i++)
    {
        for(int j=set[i-1];j<=sum;j++)
        {
            dp[j]= prev[j] + prev[j-set[i-1]];
        }
        prev=dp;
    }
    return dp[sum];
}
int main()
{
	vector<int> set = { 3,3,1,2};
	int sum=3;
	int n = set.size();
	cout<<CountSubsetSum(set, n, sum);
	return 0;
}
