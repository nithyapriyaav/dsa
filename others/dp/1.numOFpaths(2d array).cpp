#include <iostream>
using namespace std;
int numberOfPaths(int m, int n)
{
    int count[m][n];
    for(int i=0;i<m;i++)
        count[i][0]=1;
    for(int i=0;i<n;i++)
        count[0][i]=1;
        
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            count[i][j]=count[i][j-1]+count[i-1][j];
        }
    }
    return count[m-1][n-1];
}
int main()
{
	cout << numberOfPaths(2, 4);
	return 0;
}
