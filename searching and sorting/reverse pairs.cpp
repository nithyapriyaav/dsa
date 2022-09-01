#include <iostream>
using namespace std;
int merge(int arr[], int const l, int const m,int const r)
{
    // left=l to m   right=m+1 to r
    //  i<j and arr[i]>2*arr[j]
    int i=l;
    int j=m+1;
    int k=l;
    int count=0;
    int temp[10000];
    for(int i=l;i<=m;i++)
    {
        while(j<=r && arr[i]>2*arr[j])
          j++;
        count=count+(j-(m+1));
    }
    i=l;
    j=m+1;
    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
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
	int arr[]={1,3,2,3,1};
    int n=5;
	cout << "Given array is \n";
	printArray(arr, n);
	cout<<endl;
	cout<<"Reverse pairs: "<<mergeSort(arr, 0, n - 1);
	return 0;
}
