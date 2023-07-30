// C++ program to solve Rat in a Maze problem using
// backtracking
#include <bits/stdc++.h>
using namespace std;
// Maze size
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N]);

// A utility function to print solution matrix sol[N][N]
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<" "<<sol[i][j]<<" ";
		cout<<endl;
	}
}
bool isSafe(int maze[N][N], int x, int y)
{
    if(x<N && x>=0 && y<N && y>=0 && maze[x][y]==1)
       return true;
    return false;
}
bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N])
{
    if(x==N-1 && y==N-1 && maze[x][y]==1)
    {
        sol[x][y]=1;
        return true;
    }
    if(isSafe(maze,x,y))
    {
        if(sol[x][y]==1)
           return false;
        
        sol[x][y]=1;
        if(solveMazeUtil(maze,x+1,y,sol))
           return true;
        if(solveMazeUtil(maze,x,y+1,sol))
           return true;
        sol[x][y]=0;
        return false;
    }
    return false;
    
}
void solveMaze(int maze[][N])
{
    int sol[N][N];
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			sol[i][j]=0;
	}
	if(solveMazeUtil(maze,0,0,sol))
	{
	    printSolution(sol);
	}
	else
	{
	    cout<<"No solution";
	}
}
int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };
	solveMaze(maze);
	return 0;
}
