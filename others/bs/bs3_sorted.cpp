#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int bs3(int arr[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
           return mid;
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=key && key<=arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        else
        {
            if(arr[mid]<=key && key<=arr[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 33;
    cout << "Index of the element is : "
         << bs3(arr1, 0,n-1, key);
    return 0;
}