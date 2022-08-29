// using coin change
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int coinchange(int sum,vector<int> set,int n)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=1;i<=sum;i++)
        dp[0][i]=1e5;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(set[i-1]>j)
               dp[i][j]=dp[i-1][j];
            else
               dp[i][j]= min(dp[i-1][j] ,1+dp[i][j-set[i-1]]);
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
           cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][sum];
}

int fre(int *arr,int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    int count=0;
    for(auto i: mp)
    {
        int ele=i.second;
        cout<< (ele%2!=0) <<endl;
        if(ele%2==0|| ele%3==0 || ele%5==0)
         {
             int re=coinchange(ele,{2,3},2);
        count+=re;
         }
        else
           return -1;
          
    }
    return count;
    
}
int main()
{
	int arr[] = {2,2,2,2,2,2,2,2,2,2,2,3,3,2,8,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<fre(arr, n);
	return 0;
}



// simple approach
#include <bits/stdc++.h>
using namespace std;

int fre(int *arr,int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    int count=0;
    for(auto i: mp)
    {
        int ele=i.second;
        if(ele%2==0|| ele%3==0 || ele%5==0)
         {
            count+=ele/3;
            ele-=(ele/3)*3;
            if(ele!=0)
               count++;
         }
        else
           return -1;
          
    }
    return count;
    
}
int main()
{
	int arr[] = {21,21,2,2,2,2,2,2,2,2,3,3,8,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<fre(arr, n);
	return 0;
}
