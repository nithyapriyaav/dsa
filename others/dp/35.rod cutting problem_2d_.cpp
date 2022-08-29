#include <bits/stdc++.h>
using namespace std;
int cutrod(int price[],int length[],int n,int maxLen)
{
    int dp[n+1][maxLen+1];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=maxLen;w++)
        {
            if(i==0||maxLen==0)
               dp[i][w]=0;
            else if(length[i-1]>w)
               dp[i][w]=dp[i-1][w];
            else
               dp[i][w]=max( dp[i-1][w], dp[i-1][ w-length[i-1] ]+price[i-1]);
        }
    }
    return dp[n][maxLen];
}
int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;
    cout << "Maximum obtained value  is "<< cutrod(price, length, n, Max_len) << endl;
}
