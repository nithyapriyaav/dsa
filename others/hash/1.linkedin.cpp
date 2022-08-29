#include <bits/stdc++.h>
using namespace std;
void fre(int *arr,int n,int p)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(int i=0;i<p;i++)
    {
        if(mp.find(i+1)!=mp.end())
           arr[i]=mp[i+1];
        else
           arr[i]=0;
    }
}
int main()
{
	int arr[] = {1,1,2,2,3,4,5,9,10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int p=8;
	fre(arr, n,p);
	for(int i=0;i<p;i++) 
	   cout<<arr[i]<<" ";
	return 0;
}