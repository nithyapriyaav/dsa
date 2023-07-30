#include <bits/stdc++.h>

using namespace std;

struct Item {
   int value;
   int weight;
};
class Solution {
   public:
      bool static comp(Item a, Item b) 
      {
          return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
      }

   double fractionalKnapsack(int W, Item arr[], int n) 
   {
       sort(arr,arr+n,comp);
       double totalProfit=0;
       int totalWeight=0;
       for(int i=0;i<n;i++)
       {
           if(arr[i].weight+totalWeight<=W)
           {
               totalWeight+=arr[i].weight;
               totalProfit+=arr[i].value;
           }
           else
           {
               int rem=W-totalWeight;
               totalProfit+= (double)arr[i].value/ (double)arr[i].weight * (double)rem;
               break;
           }
       }
       return totalProfit;
   }

};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}