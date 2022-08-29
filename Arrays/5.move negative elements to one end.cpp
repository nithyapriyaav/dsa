void segregateElements(int arr[],int n)
    {
        int temp[n];
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=0)
               temp[j++]=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
               temp[j++]=arr[i];
        }
        memcpy(arr,temp,sizeof(temp));
        
        // 2 pointers ---- wont work,when ordering shouldn't change
        // int start=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(arr[i]>=0)
        //     {
        //         if(start != i)
        //           swap(arr[start],arr[i]);
        //         start++;
        //     }  
        // }
    }