// C++ program to count maximum consecutive
// 1's in a binary array.
#include<bits/stdc++.h>
using namespace std;

int getMaxLength(bool arr[], int n)
{
	int count = 0; 
	int maxi = 0; 
	for(int i=0;i<n;i++)
	{
	    if(arr[i]==0)
	    {
	        count=0;
	    }
	    else
	    {
	        count++;
	        maxi=max(maxi,count);
	    }
	}
	return maxi;
}

int main()
{
	bool arr[] = {1, 1, 0, 0, 1, 0, 1, 0,1, 1, 1, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << getMaxLength(arr, n) << endl;
	return 0;
}
