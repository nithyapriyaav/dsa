// 2d
#include <bits/stdc++.h>
using namespace std;
int coinChange(int arr[],int n,int amount)
{
    int dp[n+1][amount+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(j==0)
              dp[i][j]=0;
            else if(i==0)
              dp[i][j]=INT_MAX;
            else if(arr[i-1]>j)
              dp[i][j]=dp[i-1][j];
            else
              dp[i][j]= min(dp[i-1][j] ,dp[i][j-arr[i-1]]+1);
        }
    }
     for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
          cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][amount]>1e5?-1:dp[n][amount];
}
int main()
{
    int arr[] = {1, 2, 5};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 6;
    cout << coinChange(arr, m, n);
    return 0;
}



// 1d
#include <bits/stdc++.h>
using namespace std;
int coinChange(int arr[],int n,int amount)
{
    int dp[amount+1];
    memset(dp,10000,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<=n;i++)
       cout<<dp[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=arr[i-1];j<=amount;j++)
        {
              dp[j]= min(dp[j] ,dp[j-arr[i-1]]+1);
        }
    }
    for(int i=0;i<=n;i++)
       cout<<dp[i]<<" ";
    return dp[amount];
}
int main()
{
    int arr[] = {1, 2, 5};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 6;
    cout << coinChange(arr, m, n);
    return 0;
}



// greedy
min number of coins
