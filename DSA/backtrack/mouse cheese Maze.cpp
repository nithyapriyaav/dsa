// C++ program to solve Rat in a Maze problem using
// backtracking
#include <bits/stdc++.h>
using namespace std;
// Maze size
#define N 5
#define mazelength 5
bool getallpath(int maze[N][N], int x, int y)
{
    // check x,y are outside maze.
	if(x < 0 || x >= mazelength || y < 0 || y >= mazelength ){
		return false;
	}
	if(maze[x][y] == 9) {
		return true;
	}
	if(maze[x][y] != 1) return false;
	
	//mark x, y as part of the solution path
	if(maze[x][y] == 1){
		maze[x][y] = 3;
	}
	// move North
	if( getallpath(maze,x-1,y)){
		return true;
	}
	//move East
	if( getallpath(maze,x,y+1)) return true;
	//move South
	if( getallpath(maze,x+1,y)) return true;
	//move West
	if( getallpath(maze,x,y-1)) return true;
	// unMark x,y as part of the solution.
	maze[x][y] = 0;
	
	return false;
}
int getpath(int maze[][N])
{
	if(getallpath(maze,0,0))
	  return 1;
	return 0;
}
int main()
{
	int maze[N][N] = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 9, 1 },
                        { 0, 0, 0, 0, 1 } };
	cout<< getpath(maze);
 
    return 0;
	
}
