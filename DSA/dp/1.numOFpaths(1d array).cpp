#include <iostream>
using namespace std;
int numberOfPaths(int m, int n)
{
    int dp[n]={1};
    dp[0]=1;
    
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[j]+=dp[j-1];
        }
    }
    return dp[n-1];
}
// overflow occurs --> hence answer is wrong
// int factorial(int n)
// {
//     if(n==0)
//       return 1;
//     int pro=1;
//     for(int i=1;i<=n;i++)
//     {
//         pro*=i;
//     }
//     return pro;
// }
// int numberOfPathsCombi(int m, int n)
// {
//     int N=m+n-2;
//     int R=n-1;
//     N=12;
//     R=4;
//     cout<<factorial(N)<<" "<<factorial(R)<<" "<<factorial(N-R)<<endl;
//     cout<<N<<" "<<R<<" "<<N-R<<endl;
//     return factorial(N)/(factorial(R)*factorial(N-R));
// }
int numberOfPathsCombi(int m,int n)
{
    int N=n+m-2;
    int R=m-1;
    double res=1;
    if(R > N - R) 
        R = N - R;
    for(int i=1;i<=R;i++)
    {
        res=res*(N-R+i);
        res=res/i;
    }
    return (int)res;
}
int main()
{
	cout << numberOfPaths(8,9)<<endl;
	cout << numberOfPathsCombi(8,9)<<endl;
	return 0;
}
