// C++ implementation to find the length
// of longest subarray having sum 0
// using map
#include <bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int arr[],int n)
{
    unordered_map<int,int> mp;
    int sum=0,len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
           len=i+1;
        if(mp.find(sum)==mp.end())
           mp[arr[i]]=i;
        if(mp.find(sum-0)!=mp.end())
        {
            len=max(len,i-mp[sum-0]);
        }
    }
    return len;
}
int main()
{
	int arr[] = {10, -5,-5, 2, 7, 1, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Length = "
		<< lenOfLongSubarr(arr, n);
	return 0;
}