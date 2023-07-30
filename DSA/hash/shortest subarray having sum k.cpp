#include <bits/stdc++.h>
using namespace std;
int lenOfShortSubarr(int arr[],int n,int k)
{
    int sum=0;
    int left=0,len=INT_MAX;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        while(sum>=k)
        {
            len=min(len,i-left+1);
            sum-=arr[left++];
        }
    }
    return len==INT_MAX?0:len;
}
int main()
{
	int arr[] = {10, 2, 7, 1,2,3,10,5, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k=15;
	cout << "Length = "
		<< lenOfShortSubarr(arr, n, k);
	return 0;
}
