#include <bits/stdc++.h>
#include<iostream>
using namespace std;
bool compare(pair<int,int> s1,pair<int,int> s2)
{
    return(s1.second<s2.second);
}
void printMaxActivities(vector<pair<int,int>> res, int n)
{
    sort(res.begin(),res.end(),compare);
    int i=0;
    cout<< res[0].first<<" "<<res[0].second<<endl;
    for(int j=1;j<n;j++)
    {
        if(res[i].second<=res[j].first)
        {
            cout<< res[j].first<<" "<<res[j].second<<endl;
            i=j;
        }
    }
}

int main()
{
	int s[] = {1, 3, 0, 5, 8, 5};
	int f[] = {2, 4, 6, 7, 9, 9};
	vector<pair<int,int>> res;
	for(int i=0;i<6;i++)
	{
	    res.push_back({s[i],f[i]});
	    
	}
	int n = sizeof(s)/sizeof(s[0]);
	printMaxActivities(res, n);
	return 0;
}
