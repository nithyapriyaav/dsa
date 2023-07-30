// C++ program to solve Rat in a Maze problem using
// backtracking
#include <bits/stdc++.h>
using namespace std;
// Maze size
#define N 5
bool isSafe(int maze[N][N], int x, int y)
{
    if(x<N && x>=0 && y<N && y>=0 && maze[x][y]==1)
       return true;
    return false;
}
void getallpath(int maze[N][N], int x, int y,vector<string> &res,string curr)
{
    if(x==N-1 && y==N-1 && maze[x][y]==1)
    {
        res.push_back(curr);
        return;
    }
    if(isSafe(maze,x,y))
    {
        maze[x][y]=0;
        getallpath(maze,x+1,y,res,curr+'D');
        getallpath(maze,x,y+1,res,curr+'R');
        getallpath(maze,x-1,y,res,curr+'U');
        getallpath(maze,x,y-1,res,curr+'L');
           
        maze[x][y]=1;
    }
    return;
}
vector<string> findPath(int maze[][N])
{
    vector<string> res;
	getallpath(maze,0,0,res,"");
	return res;
}
int main()
{
	int maze[N][N] = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 } };
	vector<string> ans = findPath(maze);
    for(auto i : ans)
    cout<<i<<" ";
 
    return 0;
	
}
