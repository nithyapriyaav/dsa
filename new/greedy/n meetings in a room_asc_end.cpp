 static bool compare(pair<int,int> s1,pair<int,int> s2)
    {
        return(s1.second<s2.second);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++)
        {
            res.push_back({start[i],end[i]});
        }
        sort(res.begin(),res.end(),compare);
        int i=0,count=1;
        // cout<< 1<<" ";
        for(int j=1;j<n;j++)
        {
            if(res[i].second<res[j].first)
            {
                // cout<<j+1<<" ";
                count++;
                i=j;
            }
        }
        // cout<<endl;
        return count;
    }