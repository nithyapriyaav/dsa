#include <bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
	int left[n];
	int right[n];
	int maxWater = 0;
	left[0] = arr[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], arr[i]);
		
	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], arr[i]);

	for(int i=0;i<n;i++)
	{
	    maxWater+=min(right[i],left[i])-arr[i];
	}

	return maxWater;
}
int main()
{
	int arr[] = { 3,0,2,0,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum water that can be accumulated is "<< findWater(arr, n);
	return 0;
}
