void sort012(int a[], int n)
{
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0) cnt0++;
        else if(a[i]==1) cnt1++;
        else cnt2++;
    }
    int i=0;
    while(cnt0--)
      a[i++]=0;
    while(cnt1--) 
      a[i++]=1;
    while(cnt2--)
      a[i++]=2;
}