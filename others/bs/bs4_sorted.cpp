#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int bs4(int arr[],int low,int high)
{
    // This condition is needed to handle the case when array is not rotated at all 
    if(high<low)
        return arr[0];
    // If there is only one element left 
    if(low==high)
        return arr[low];
        
    int mid=(low+high)/2;
    
    if(arr[mid]>arr[mid+1])
        return arr[mid+1];
    if(arr[mid-1]>arr[mid])
        return arr[mid];
        
    if(arr[mid]>arr[high])
        return bs4(arr,mid+1,high);
    return bs4(arr,low,mid-1);
}
int main()
{
    int arr1[] = { 10,30,40,-1,0,1, 2, 3 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Minimum element is : "
         << bs4(arr1, 0,n-1);
    return 0;
}