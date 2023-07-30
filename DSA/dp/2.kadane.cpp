#include <iostream>
using namespace std;
int kadane(int arr[], int n)
{
    int max_so_far=0;
    int max_ending_here=0;
    for(int i=0;i<n;i++)
    {
        max_ending_here+=arr[i];
        max_ending_here=max(max_ending_here,arr[i]);
        max_so_far=max( max_so_far, max_ending_here);
    }
    return max_so_far;
}
int main()
{
	int arr[]={1,-2,3,-1,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<< kadane(arr,n);
	return 0;
}
