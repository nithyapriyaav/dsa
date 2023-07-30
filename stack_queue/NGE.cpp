
#include <bits/stdc++.h>

using namespace std;
void printNGE(int arr[], int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
      //  if(s.empty())
      //  {
      //      s.push(arr[i]);
      //      continue;
      //  }
        while(!s.empty() && s.top()<arr[i])
        {
            cout<<s.top()<< "-->"<<arr[i]<<endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        cout<<s.top()<< "-->"<<-1<<endl;
        s.pop();
    }
}
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}


// same order
#include <bits/stdc++.h>

using namespace std;
void printNGE(int arr[], int n)
{
    stack<int> s;
    int res[n];
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()<=arr[i])
            s.pop();
        res[i]= s.empty()?-1:s.top();
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<< arr[i]<<"-->"<<res[i]<<endl;
    }
}
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}
