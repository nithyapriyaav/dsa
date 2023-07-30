#include <bits/stdc++.h>
#define R 4
#define C 4
using namespace std;
 
// A function to rotate a matrix mat[][] of size R x C.
// Initially, m = R and n = C
void rotatematrix(int m, int n, int mat[R][C])
{
      int top=0,down=m-1,left=0,right=n-1;
      int prev,curr;
       
       
        while(top<=down && left<=right)
        {
      
            prev=mat[top+1][left];
         
                for(int i=left;i<=right;i++)
                {
                    curr=mat[top][i];
                    mat[top][i]=prev;
                    prev=curr;
                }
                top++;
         
        
                for(int i=top;i<=down;i++)
                {
                    curr=mat[i][right];
                    mat[i][right]=prev;
                    prev=curr;
                }

                right--;
        
           
                for(int i=right;i>=left;i--)
                {
                    curr=mat[down][i];
                    mat[down][i]=prev;
                    prev=curr;
                }
                down--;
           
         
             for(int i=down;i>=top;i--)
                {
                    curr=mat[i][left];
                    mat[i][left]=prev;
                    prev=curr;
                }
                left++;
           
      
        }
       
 
    // Print rotated matrix
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
        cout << mat[i][j] << " ";
        cout << endl;
    }
}
 
/* Driver program to test above functions */
int main()
{
    // Test Case 1
    int a[R][C] = { {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16} };
 
    // Test Case 2
    /* int a[R][C] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                    };
    */ rotatematrix(R, C, a);
    return 0;
}