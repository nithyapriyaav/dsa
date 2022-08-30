#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{
	int left = 0;
	int right = n-1;
	int r_max = 0,l_max=0;
	int res=0;
	while(left<=right)
	{
	    if(r_max<=l_max)
	    {
	        res+=max(0,r_max-arr[right]);
	        r_max=max(r_max,arr[right]);
	        right--;
	    }
	    else
	    {
	        res+=max(0,l_max-arr[left]);
	        l_max=max(l_max,arr[left]);
	        left++;
	    }
	}
	return res;
}

// Driver code
int main() {
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int N = sizeof(arr)/sizeof(arr[0]);
	cout << maxWater(arr, N) << endl;
	return 0;
}

// This code is contributed by avanitrachhadiya2155
