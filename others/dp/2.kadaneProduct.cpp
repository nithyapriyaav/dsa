#include <iostream>
using namespace std;
int kadane(int arr[], int n)
{
    int max_so_far=0;
    int max_ending_here=1;
    int min_ending_here=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
            swap(max_ending_here,min_ending_here);
        max_ending_here=max(max_ending_here*arr[i],arr[i]);
        min_ending_here=min(min_ending_here*arr[i],arr[i]);
        max_so_far=max(max_ending_here,max_so_far);
    }
    return max_so_far;
}
int main()
{
	int arr[]={1, -2, -3, 0, 7, -8, -2};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<< kadane(arr,n);
	return 0;
}
