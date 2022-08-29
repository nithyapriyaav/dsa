#include <iostream>
using namespace std;
int rob(int nums[],int n) 
{
        int dp[n];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
}
int main()
{
	int hval[] = { 6, 7, 1, 3, 8, 2, 4 };
	int n = sizeof(hval) / sizeof(hval[0]);
	cout << "Maximum loot possible : " << rob(hval, n);
	return 0;
}
