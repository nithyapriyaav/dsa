// C++ program to demonstrate insertion
// into a vector of vectors

#include <iostream>
#include <vector>
using namespace std;

// Defining the rows and columns of
// vector of vectors
#define ROW 5
#define COL 3

int main()
{
	// Initializing the vector of vectors
	vector<vector<string> > vec;

	// Elements to insert in column
	vector<string> s={"d","e","13"};

	// Inserting elements into vector
	for (int i = 0; i < ROW; i++) {
		// Vector to store column elements
		vector<string> v1;
		
		for (int j = 0; j < COL; j++) {
			v1.push_back(s[j]);
		}

		// Pushing back above 1D vector
		// to create the 2D vector
		vec.push_back(v1);
		s={"A","b","11"};
	}

	// Displaying the 2D vector
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	
	// display all vechicles of type "b"
	for (int i = 0; i < vec.size(); i++) 
	{
		 if(vec[i][1]=="b")
		 {
		     for(auto j:vec[i])
		        cout<<j<<" ";
		 }
		cout << endl;
	}
	return 0;
}
