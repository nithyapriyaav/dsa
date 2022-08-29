// C++ code to search key in bitonic array
#include <iostream>

using namespace std;

// Function for binary search in ascending part
int ascendingBinarySearch(int arr[], int low,
						int high, int key)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
           return mid;
        else if(arr[mid]>key)
           high=mid-1;
        else
           low=mid+1;
    }
    return -1;
}


// Function for binary search in
// descending part of array
int descendingBinarySearch(int arr[], int low,
						int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

// finding bitonic point
int findBitonicPoint(int arr[], int n,
					int l, int r)
{
    int index=0;
    int mid=(l+r)/2;
    if(l<=r)
    {
        if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1])
           return mid;
        else if(arr[mid]>=arr[mid-1] && arr[mid+1]>=arr[mid])
           index=findBitonicPoint(arr,n,mid,r);
        else if(arr[mid]<=arr[mid-1] && arr[mid+1]<=arr[mid])
           index=findBitonicPoint(arr,n,l,mid);
    }
    return index;
}

// Function to search key in
// bitonic array
int searchBitonic(int arr[], int n,
				int key, int index)
{
    if(arr[index]<key)
       return -1;
    if(arr[index]==key)
       return index;
    else
    {
        int in=ascendingBinarySearch(arr,0,index,key);
        if(in!=-1)
           return in;
        return descendingBinarySearch(arr,index,n-1,key);
    }
}

// Driver code
int main()
{
	int arr[] = { -8, 1, 2, 3, 4, 5, -2, -3 };
	int key = -8;
	int n, l, r;
	n = sizeof(arr) / sizeof(arr[0]);
	int index;

	// Function call
	index = findBitonicPoint(arr, n, 0,n-1);

	int x = searchBitonic(arr, n, key, index);

	if (x == -1)
		cout << "Element Not Found" << endl;
	else
		cout << "Element Found at index " << x << endl;

	return 0;
}
