// C++ program to find maximum number of thieves caught
#include <bits/stdc++.h>
using namespace std;

// Returns maximum number of thieves that can be caught.
int policeThief(char arr[], int n, int k)
{
// Initialize the current lowest indices of
// policeman in pol and thief in thi variable as -1
int pol = -1, thi = -1, res = 0;
// Find the lowest index of policemen
for (int i = 0; i < n; i++) {
	if (arr[i] == 'P') {
	pol = i;
	break;
	}
}

// Find the lowest index of thief
for (int i = 0; i < n; i++) {
	if (arr[i] == 'T') {
	thi = i;
	break;
	}
}

if(thi==-1 || pol==-1)
  return 0;
while(thi<n && pol<n)
{
    if(abs(thi-pol)<=k)
    {
        res++;
        while(++thi<n && arr[thi]=='P');
        while(++pol<n && arr[pol]=='T');
    }
    else if(thi<pol)
    {
        while(++thi<n && arr[thi]=='P');
    }
    else
    {
        while(++pol<n && arr[pol]=='T');
    }
    
}
return res;
}

int main()
{
int k, n;
char arr1[] = { 'P', 'T', 'T', 'P', 'T' };
k = 2;
n = sizeof(arr1) / sizeof(arr1[0]);
cout << "Maximum thieves caught: " << policeThief(arr1, n, k) << endl;

char arr2[] = { 'T', 'T', 'P', 'P', 'T', 'P' };
k = 2;
n = sizeof(arr2) / sizeof(arr2[0]);
cout << "Maximum thieves caught: " << policeThief(arr2, n, k) << endl;

char arr3[] = { 'P', 'T', 'P', 'T', 'T', 'P' };
k = 3;
n = sizeof(arr3) / sizeof(arr3[0]);
cout << "Maximum thieves caught: " << policeThief(arr3, n, k) << endl;

return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
// C++ program to find maximum number of thieves caught
#include <bits/stdc++.h>
using namespace std;

// Returns maximum number of thieves that can be caught.
int policeThief(char arr[], int n, int k)
{
// Initialize the current lowest indices of
// policeman in pol and thief in thi variable as -1
int pol = -1, thi = -1, res = 0;
// Find the lowest index of policemen
for (int i = 0; i < n; i++) {
	if (arr[i] == 'P') {
	pol = i;
	break;
	}
}

// Find the lowest index of thief
for (int i = 0; i < n; i++) {
	if (arr[i] == 'T') {
	thi = i;
	break;
	}
}

if(thi==-1 || pol==-1)
  return 0;
while(thi<n && pol<n)
{
    if(abs(thi-pol)<=k)
    {
        res++;
        while(++thi<n && arr[thi]=='P');
        while(++pol<n && arr[pol]=='T');
    }
    else if(thi<pol)
    {
        while(++thi<n && arr[thi]=='P');
    }
    else
    {
        while(++pol<n && arr[pol]=='T');
    }
    
}
return res;
}

int main()
{
int k, n;
char arr1[] = { 'P', 'T', 'T', 'P', 'T' };
k = 2;
n = sizeof(arr1) / sizeof(arr1[0]);
cout << "Maximum thieves caught: " << policeThief(arr1, n, k) << endl;

char arr2[] = { 'T', 'T', 'P', 'P', 'T', 'P' };
k = 2;
n = sizeof(arr2) / sizeof(arr2[0]);
cout << "Maximum thieves caught: " << policeThief(arr2, n, k) << endl;

char arr3[] = { 'P', 'T', 'P', 'T', 'T', 'P' };
k = 3;
n = sizeof(arr3) / sizeof(arr3[0]);
cout << "Maximum thieves caught: " << policeThief(arr3, n, k) << endl;

return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
