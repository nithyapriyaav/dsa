#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=6;
    int res,count=0;
    vector<int> arr(n);
    for(int i=1;i<=n;i++)
    {
        arr[i-1]=i;
    }
    for(int i=0;i<n;i++)
    {
     
        if(arr[i]%2!=0)
         {
             res=3*arr[i]+1;
            //  cout<<res<<endl;
             auto it=find(arr.begin(),arr.end(),res);
            //  cout<<*it<<endl;
             if(it==arr.end())
                count++;
         }
         res=arr[i]*2;
    //  cout<<res<<endl;
        auto it=find(arr.begin(),arr.end(),res);
        if(it==arr.end())
            count++;
        
    }
      
    cout<< count<<endl;

    return 0;
}
