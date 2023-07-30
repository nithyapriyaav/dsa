/* Dynamic Programming implementation of Box Stacking problem */
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Box
{
    int h,w,d;
};
int cmpfunc(const void * a, const void * b) {
   return ( (*(Box *)b).d * (*(Box *)b).w ) -
          ( (*(Box *)a).d * (*(Box *)a).w );
}
int maxStackHeight(Box arr[],int n)
{
    // find all rotations
    int rotations=3*n;
    Box rot[rotations];
    int index=0;
    for(int i=0;i<n;i++)
    {
        rot[index].h=arr[i].h;
        rot[index].d=max(arr[i].d,arr[i].w);
        rot[index].w=min(arr[i].d,arr[i].w);
        index++;
        
        rot[index].h=arr[i].w;
        rot[index].d=max(arr[i].h,arr[i].d);
        rot[index].w=min(arr[i].h,arr[i].d);
        index++;
        
        rot[index].h=arr[i].d;
        rot[index].d=max(arr[i].h,arr[i].w);
        rot[index].w=min(arr[i].h,arr[i].w);
        index++;
    }
    
    // sort the rot array in desc order of base area
    qsort(rot,rotations,sizeof(rot[0]),cmpfunc);
    
    // LIS
    int lis[rotations]={0};
    for(int i=0;i<rotations;i++)
    {
        lis[i]=rot[i].h;
    }
    for(int i=1;i<rotations;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(rot[i].w<rot[j].w && rot[i].d<rot[j].d && lis[i]<lis[j]+rot[i].h)
            {
                lis[i]=lis[j]+rot[i].h;
            }
        }
    }
    return *max_element(lis,lis+rotations);
    // int res=-1;
    // for(int i=0;i<rotations;i++)
    // {
    //     res=max(res,lis[i]);
    // }
    // return res;
}
int main()
{
   Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<< "The maximum possible height of stack is "<< maxStackHeight (arr, n) ;
   return 0;
}

//or sort in ASC and 
//if(rot[i].w>rot[j].w && rot[i].d>rot[j].d && lis[i]<lis[j]+rot[i].h)
//            {
//                lis[i]=lis[j]+rot[i].h;
//            }