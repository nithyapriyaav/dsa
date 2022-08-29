#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)
{
    vector<int> lis(arr,arr+n);
    for (int i = 1; i < n; i++) 
	{
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + arr[i])
				lis[i] = lis[j] + arr[i];
	}

	return *max_element(lis.begin(), lis.end());

}

int main()
{
	int arr[] = {11, 101, 2, 3, 100, 40, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Sum of maximum sum increasing "
			"subsequence is " << maxSumIS( arr, n ) << endl;
	return 0;
}

