pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> res;
    res.first=INT_MAX;
    res.second=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]<res.first)
        {
            res.first=a[i];
        }
        if(a[i]>res.second)
        {
            res.second=a[i];
        }
    }
    return res;
}