// C++ implementation to find the length
// of longest subarray having sum k

// using unordered map
#include <bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int arr[],int n,int k)
{
    unordered_map<int,int> mp;
    int sum=0,len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
           len=i+1;
        if(mp.find(sum)==mp.end())
           mp[arr[i]]=i;
        if(mp.find(sum-k)!=mp.end())
        {
            len=max(len,i-mp[sum-k]);
        }
    }
    return len;
}
int main()
{
	int arr[] = {10, 5, 2, 7, 1, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 15;
	cout << "Length = "
		<< lenOfLongSubarr(arr, n, k);
	return 0;
}


// using 2 pointers
#include <bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int arr[],int n,int k)
{
    int sum=0;
    int left=0,len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        while(sum>=k)
        {
            len=max(len,i-left+1);
            sum-=arr[left++];
        }
    }
    return len;
}
int main()
{
	int arr[] = {10, 5, 2, 7, 1,2,3, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k=15;
	cout << "Length = "
		<< lenOfLongSubarr(arr, n, k);
	return 0;
}
