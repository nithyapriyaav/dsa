#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) 
   {
       sort(arr,arr+n,comparison);
       int maxi=0;
       for(int i=0;i<n;i++)
       {
           maxi=max(arr[i].dead,maxi);
       }
       int res[maxi+1];
       memset(res,-1,sizeof(res));
       int countJobs=0,countProfit=0;
       for(int i=0;i<n;i++)
       {
           for (int j = arr[i].dead; j > 0; j--) 
           {
               if(res[j]==-1)
                {
                  res[j]=arr[i].id;
                // res[j]=i;
                  countJobs++;
                 countProfit+=arr[i].profit;
                 break;
                 }
           }
       }
       return {countJobs,countProfit};
   }
};
int main() {
   int n = 8;
   Job arr[n] = {{16,2,80},{3,6,70},{4,6,65},{2,5,60},{5,4,25},{8,2,22},{1,4,20},{7,2,10}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 