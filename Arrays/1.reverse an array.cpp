#include <iostream>
using namespace std;
void rev(int a[],int n)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        rev(a,n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
	return 0;
}