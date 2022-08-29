#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    long long minCost(long long arr[], long long n) {
       // priority_queue<int ,vector<int >,greater<int >> pq(arr,arr+n);
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(long long i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        long long count=0;
        while(pq.size()>1)
        {
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            count+=a+b;
            pq.push(a+b);
        }
        return count;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
