#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    int left=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[left])
        {
            left++;
            arr[left]=arr[i];
        //   swap(arr[i],arr[left]);
        }
    }
    return left+1;
}

int main()
{
	int arr[] = { 1,1, 2, 2, 3, 4, 4, 4, 5, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	n = removeDuplicates(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}

