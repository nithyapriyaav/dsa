// C++ program for optimal allocation of pages
#include <bits/stdc++.h>
using namespace std;
bool allocationIsPossible(int arr[],int n,int m,int barrier)
{
    int allocatedStudent=1,pages=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>barrier)
            return false;
        if(pages+arr[i]>barrier) 
        {
            allocatedStudent++;
            pages=arr[i];
            if(allocatedStudent>m)
               return false;
        }
        else
            pages+=arr[i];
    }
    return true;
}
int findPages(int arr[],int n,int m)
{
    int sum=0;
    if(n<m) 
       return -1;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int res=INT_MAX,low=0,high=sum;
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(allocationIsPossible(arr,n,m,mid))
        {
            res=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return res;
}
int main()
{
	int arr[] = { 123,33,12, 34, 67, 90 };
	int n = sizeof arr / sizeof arr[0];
	int m = 2; // No. of students
	cout << "Minimum number of pages = "
		<< findPages(arr,n, m) << endl;
	return 0;
}
