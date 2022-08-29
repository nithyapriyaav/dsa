#include <stdio.h>

// Function to implement lower_bound
int lower_bound(int arr[], int N, int X)
{
	int mid;
	int low = 0;
	int high = N-1;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (X <= arr[mid]) {
			high = mid-1;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}

// Function to implement upper_bound
int upper_bound(int arr[], int N, int X)
{
	int mid;
	int low = 0;
	int high = N-1;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (X >= arr[mid]) {
			low = mid + 1;
		}
		else {
			high = mid-1;
		}
	}
	return high+1;  //low
}
void printBound(int arr[], int N, int X)
{
	int idx;
	if (lower_bound(arr, N, X) == N) {
		printf("Lower bound doesn't exist");
	}
	else {
		idx = lower_bound(arr, N, X);
		printf("Lower bound of %d is"
			"% d at index % d\n ",
			X,
			arr[idx], idx);
	}
	if (upper_bound(arr, N, X) == N) {
		printf("Upper bound doesn't exist");
	}
	else {
		idx = upper_bound(arr, N, X);
		printf("Upper bound of %d is"
			"% d at index % d\n ",
			X,
			arr[idx], idx);
	}
}
int main()
{
	int arr[] = { 4, 6, 10, 12, 12, 12,13 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int X = 12;
	printBound(arr, N, X);
	return 0;
}
