#include <bits/stdc++.h>
using namespace std;
int knapSack(int W,int wt[],int val[],int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0||w==0)
               dp[i][w]=0;
            else if(wt[i-1]>w)
               dp[i][w]=dp[i-1][w];
            else
               dp[i][w]=max( dp[i-1][w], dp[i-1][ w-wt[i-1] ]+val[i-1]);
        }
    }
    return dp[n][W];
}
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}


// space optimization
#include <bits/stdc++.h>
using namespace std;
int knapSack(int W,int wt[],int val[],int n)
{
    vector<int> dp(W+1);
    vector<int> prev(W+1);
    for(int i=0;i<=W;i++)
        dp[i]=0;
    prev=dp;
    for(int i=0;i<=n;i++)
    {
        for(int w=wt[i-1];w<=W;w++)
        {
               dp[w]=max( prev[w], prev[ w-wt[i-1] ]+val[i-1]);
        }
        prev=dp;
    }
    return dp[W];
}
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}
