#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergedIntervals(vector<vector<int>> intervals)
{
    vector<vector<int>> res;
    int n=intervals.size();
    if(n==0)
       return res;
    sort(intervals.begin(),intervals.end());
    vector<int> temp=intervals[0];
    for(auto i:intervals)
    {
        if(temp[1]>=i[0])
            temp[1]=max(temp[1],i[1]);
        else
        {
            res.push_back(temp);
            temp=i;
        }
    }
    res.push_back(temp);
    return res;
}
int main()
{
    vector<vector<int>> intervals;
    intervals={{1,3},{2,6},{8,10},{15,18},{9,9}};
    vector<vector<int>> res=mergedIntervals(intervals);
    for(auto i:res)
    {
        cout<<i[0]<<" "<<i[1]<<endl;
    }
}



// C++ program to implement a stack that supports
// getMinimum() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;
vector < pair < int, int >> merge(vector<pair < int, int >> arr)
{
    pair<int,int> temp;
    vector < pair < int, int >> res;
    sort(arr.begin(),arr.end());
    temp=arr[0];
    for(int i=0;i<arr.size();i++)
    {
        if(temp.second>arr[i].first)
        {
            temp.second=max(temp.second,arr[i].second);
        }
        else
        {
            res.push_back(temp);
            temp=arr[i];
        }
    }
    res.push_back(temp);
    return res;
}

int main()
{
    vector<pair<int,int>> arr;
    arr = {{1,3},{2,4},{2,6},{9,11},{15,18},{16,17},{8,9},{8,10}};
    vector < pair < int, int >> ans = merge(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (auto it: ans) {
        cout << it.first << " " << it.second << "\n";
    }
}

