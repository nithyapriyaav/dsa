 // dp
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        vector<int> lis(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]
                                                   && lis[i]<lis[j]+1)
                {
                    lis[i]=lis[j]+1;
                }
            }
        }
        return *max_element(lis.begin(),lis.end());
    }
};
int main(){
   Solution ob;
   vector<vector<int>> v = {{5,5}, {6,4}, {6,8}, {2,3}};
   cout << (ob.maxEnvelopes(v));
   return 0;
}

// b.s
// #include <bits/stdc++.h>
// using namespace std;
//   class Solution {
// public: 
//     static bool cmp(vector<int> &a, vector<int> &b)
//     {
//         if(a[0]==b[0])
//             return a[1]>b[1];
//         return a[0]<b[0];
//     }
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         sort(envelopes.begin(),envelopes.end(),cmp);
//         int n=envelopes.size();
//         vector<int> lis;
//         lis.push_back(envelopes[0][1]);     
//         for(int i=1;i<n;i++)
//         {
//             auto it=lower_bound(lis.begin(),lis.end(),envelopes[i][1]);
//             if(it==lis.end()) 
//                 lis.push_back(envelopes[i][1]);
//             else
//                 *it=envelopes[i][1];
//         }
//         return lis.size();
//     }
// };
// int main(){
//   Solution ob;
//   vector<vector<int>> v = {{4,5}, {4,6}, {6,7}, {2,3},{1,1}};
//   cout << (ob.maxEnvelopes(v));
//   return 0;
// }
