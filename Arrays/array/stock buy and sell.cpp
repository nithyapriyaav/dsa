#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr)
{
    int profit=0;
    int mini=arr[0];
    int cost;
    for(int i=1;i<arr.size();i++)
    {
        cost=arr[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,arr[i]);
    }
    return profit;
}
// buy then sell
// buy amount-less
// sell amount-high
int main() {
    vector<int> arr = {7,6,4,3,1};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}