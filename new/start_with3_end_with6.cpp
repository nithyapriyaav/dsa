// C++ program to Count total sub-array
// which start and end with same element

#include <bits/stdc++.h>
using namespace std;

// Function to find total sub-array
// which start and end with same element
void cntArray(int A[], int N,int start,int end)
{
	int result = 0;
	bool t1=false;
	for (int i = 0; i < N; i++) 
	{
		if(start==A[i] && t1==false)
		{
		    t1=!t1;
		}
		if(end==A[i] && t1==true)
		{
		    t1=!t1;
		    result++;
		}
	}

	// print the result
	cout << result << endl;
}

// Driver code
int main()
{
	int A[] = { 1, 5, 6, 1, 9,5, 6,9,1,6,1,9 };
	int N = sizeof(A) / sizeof(int);

	cntArray(A, N,6,9);

	return 0;
}
