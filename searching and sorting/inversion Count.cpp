#include <iostream>
using namespace std;
int merge(int arr[], int const l, int const m,int const r)
{
    // left=l to m   right=m+1 to r
    int i=l;
    int j=m+1;
    int k=l;
    int count=0;
    int temp[10000];
    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {
            count=count+(m+1-i);
            temp[k++]=arr[j++];
        }
    }
    while(i<=m)
        temp[k++]=arr[i++];
    while(j<=r)
        temp[k++]=arr[j++];
    for(int a=l;a<=r;a++)
    {
        arr[a]=temp[a];
    }
    return count;
}
int mergeSort(int arr[],int low,int high)
{
    int count=0;
    if(low<high)
    {
    int mid=(high+low) / 2;
    count+=mergeSort(arr,low,mid);
    count+=mergeSort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);
    }
    return count;
}
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}
int main()
{
	int arr[]={1,20,6,7,5,8,11,3};
    int n=8;
	cout << "Given array is \n";
	printArray(arr, n);
	cout<<endl;
	cout<<"Inversion count: "<<mergeSort(arr, 0, n - 1);
	return 0;
}
