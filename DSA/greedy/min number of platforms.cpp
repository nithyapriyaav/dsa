int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int count=0,plat=0;
    int i=0,j=0;
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            plat++;
            i++;
            count=max(count,plat);
        }
        else
        {
            plat--;
            j++;
        }
    }
    return count;
}