#include <bits/stdc++.h>
using namespace std;
int upper_bound(int arr2[],int l,int r,int x)
{
    while(r>=l)
    {
        int m=l+(r-l)/2;
        if(arr2[m]<=x)
          l=m+1;
        else
          r=m-1;
    }
    return r+1;
}
// int upper_bound(int arr2[],int l,int r,int x)
// {
//     if(r>=l)
//     {
//         int m=l+(r-l)/2;
//         if(arr2[m]<=x)
//           return upper_bound(arr2,m+1,r,x);
//         else
//           return upper_bound(arr2,l,m-1,x);
//     }
//     return r+1;
// }
void fun(int arr1[], int arr2[],int m, int n)
{
    // sort 2nd array
    sort(arr2,arr2+n);
    for(int i=0;i<m;i++)
    {
        int index=upper_bound(arr2,0,n-1,arr1[i]);
        cout<<index<<" ";
    }
}

int main()
{
    int arr1[] = { 1, 2, 3, 4, 7, 9 };
    int arr2[] = { 0, 1, 2, 1, 1, 4 };
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    fun(arr1, arr2, m, n);
    return 0;
}