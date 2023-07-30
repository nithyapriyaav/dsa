
#include <bits/stdc++.h>
using namespace std;
int coinChange(int coins[],int n,int amount)
{
    int dp[amount+1]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=coins[i-1];j<=amount;j++)
        {
             dp[j]=dp[j]+dp[j-coins[i-1]];
        }
    }
    return dp[amount];
}
int main()
{
    int arr[] = {1, 2, 5};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 5;
    cout << coinChange(arr, m, n);
    return 0;
}
