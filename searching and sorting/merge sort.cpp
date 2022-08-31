#include <iostream>
using namespace std;
void merge(int arr[], int const l, int const m,int const r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
       L[i]=arr[l+i];
    for(int j=0;j<n2;j++)
       R[j]=arr[m+j+1];
    k=l;
    i=j=0;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}
void mergeSort(int arr[],int low,int high)
{
    if(low>=high)
        return;
    int mid=(high+low) / 2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);
	
	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}




// easy
// #include <iostream>
// using namespace std;
// int merge(int arr[], int const l, int const m,int const r)
// {
//     int count=0;
//     int i,j,k;
//     int n1=m-l+1;
//     int n2=r-m;
//     int L[n1];
//     int R[n2];
//     for(int i=0;i<n1;i++)
//       L[i]=arr[l+i];
//     for(int j=0;j<n2;j++)
//       R[j]=arr[m+j+1];
//     k=l;
//     i=j=0;
//     while(i<n1 && j<n2)
//     {
//         if(L[i]<=R[j])
//             arr[k++]=L[i++];
//         else
//         {
//             cout<<L[i]<<">"<<R[j]<<endl;
//             count+= (m - i);
//             arr[k++]=R[j++];
//         }
//     }
//     while(i<n1)
//         arr[k++]=L[i++];
//     while(j<n2)
//         arr[k++]=R[j++];
//     return count;
// }
// int mergeSort(int arr[],int low,int high)
// {
//     int count=0;
//     if(low<high)
//     {
//     int mid=(high+low) / 2;
//     count+=mergeSort(arr,low,mid);
//     count+=mergeSort(arr,mid+1,high);
//     count+=merge(arr,low,mid,high);
//     }
//     return count;
    
// }
// void printArray(int A[], int size)
// {
// 	for (auto i = 0; i < size; i++)
// 		cout << A[i] << " ";
// }
// int main()
// {
// 	int arr[]={1,20,6,7,5,8,11,3};
//     int arr_size=8;

// 	cout << "Given array is \n";
// 	printArray(arr, arr_size);
// 	cout<<endl;
// 	cout<<mergeSort(arr, 0, arr_size - 1);
// 	return 0;
// }


#include <iostream>
using namespace std;
void merge(int arr[], int const l, int const m,int const r)
{
    int i=l;
    int j=m+1;
    int k=l;
    int temp[10000];
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
}
void mergeSort(int arr[],int low,int high)
{
    int count=0;
    if(low<high)
    {
    int mid=(high+low) / 2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
    }
}
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}
int main()
{
	int arr[]={1,20,6,7,5,8,11,3};
    int arr_size=8;
	cout << "Given array is \n";
	printArray(arr, arr_size);
	cout<<endl;
	mergeSort(arr, 0, arr_size - 1);
	cout << "Sorted array is \n";
	printArray(arr, arr_size);
	cout<<endl;
	return 0;
}

