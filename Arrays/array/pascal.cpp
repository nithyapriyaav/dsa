// C++ program to implement a stack that supports
// getMinimum() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;
void pascal(int n)
{
    // vector<vector<int>> mat(n,vector<int>(n));
    vector<vector<int>> mat(n);
    for(int i=0;i<n;i++)
    {
        mat[i].resize(i+1);
        mat[i][0]=mat[i][i]=1;
        for(int j=1;j<i;j++)
           mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
    }
    for(auto i:mat)
    {
        for(auto j:i)
           cout<<j<<" ";
        cout<<endl;
    }
}

int main()
{
    int n=10;
    pascal(n);
	return 0;
}
