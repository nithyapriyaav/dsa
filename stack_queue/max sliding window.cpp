#include<bits/stdc++.h>

using namespace std;

vector < int > maxSlidingWindow(vector < int > & nums, int k) 
{
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<nums.size();i++)
    {
        if(!dq.empty() && dq.front()==i-k)
           dq.pop_front();
        while(!dq.empty() && nums[dq.front()]<nums[i])
            dq.pop_back();
        dq.push_back(i);
        if(i>=k-1 &&  !dq.empty())
           res.push_back(nums[dq.front()]);
    }
    return res;
}
int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {4,0,3,3,2,3,6,8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}