// C++ program to find substring with equal
// number of 0's, 1's and 2's
#include <bits/stdc++.h>
using namespace std;

// Method to count number of substring which
// has equal 0, 1 and 2
int getSubstringWithEqual012(string str)
{
	int N = str.length();

	// map to store, how many times a difference
	// pair has occurred previously
	map<pair<int, int>, int> mp;
	mp[make_pair(0, 0)] = 1;

	// zc (Count of zeroes), oc(Count of 1s)
	// and tc(count of twos)
	// In starting all counts are zero
	int zc = 0, oc = 0, tc = 0;

	// looping into string
	int res = 0; // Initialize result
	for (int i = 0; i < N; ++i) {
	
		// increasing the count of current character
		if (str[i] == '0')
			zc++;
		else if (str[i] == '1')
			oc++;
		else
			tc++; // Assuming that string doesn't contain
				// other characters

		// making pair of differences (z[i] - o[i],
		// z[i] - t[i])
		pair<int, int> tmp = make_pair(zc - oc, zc - tc);

		// Count of previous occurrences of above pair
		// indicates that the subarrays forming from
		// every previous occurrence to this occurrence
		// is a subarray with equal number of 0's, 1's
		// and 2's
		res = res + mp[tmp];
		cout<<tmp.first<<" "<<tmp.second<<endl;

		// Increasing the count of current difference
		// pair by 1
		mp[tmp]++;
	}
	for(auto i:mp)
	{
	    cout<<i.first.first<<" "<<i.first.second<<"-->"<<i.second<<endl;
	}

	return res;
}

// Driver's code
int main()
{
	string str = "0102010";

	// Function call
	cout << getSubstringWithEqual012(str) << endl;
	return 0;
}
