#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
		
	printf("\n");
}
int AreAll9s(int* num, int n )
{
	int i;
	for(i = 0; i < n; ++i)
		if (num[i] != 9)
			return 0;
			
	return 1;
}
void generateNextPalindromeUtil (int num[], int n )
{
    // even -- mid
    // odd -- mid+1
    int mid=n/2;
    int i=mid-1;
    int j=(n%2==1)?mid+1:mid;
    
    while(i>=0 && num[i]==num[j])
       i--,j++;
    bool leftsmaller=false;
    if(i<0 || num[i]<num[j])
       leftsmaller=true;
       
    while(i>=0)
    {
        num[j]=num[i];
        j++;
        i--;
    }
    
    if(leftsmaller==true)
    {
        int i=mid-1;
        int carry=1;
        if(n%2==1)
        {
            num[mid]+=carry;
            carry=num[mid]/10;
            num[mid]%=10;
            j=mid+1;
        }
        else
            j=mid;
            
        while(i>=0)
        {
            num[i]+=carry;
            carry=num[i]/10;
            num[i]%=10;
            num[j++]=num[i--];
        }
    }
}
void generateNextPalindrome(int num[], int n)
{
    if(AreAll9s(num,n))
    {
        cout<< "1";
        for(int i=1;i<n;i++)
           cout<< "0";
        cout<< "1";
    }
    else
    {
        generateNextPalindromeUtil(num,n);
        printArray(num,n);
    }
}

int main()
{
	int num[] = { 9, 4, 1,6,7, 8 };
	int n = sizeof(num) / sizeof(num[0]);
	generateNextPalindrome(num, n);
	return 0;
}

