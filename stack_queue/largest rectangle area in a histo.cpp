#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      stack < int > s;
      int leftsmall[n], rightsmall[n];
      for(int i=0;i<n;i++)
      {
          while(!s.empty() && heights[s.top()]>=heights[i])
             s.pop();
          if(s.empty())
             leftsmall[i]=0;
          else
             leftsmall[i]=s.top()+1;
          s.push(i);
          
      }
      for(int i=n-1;i>=0;i--)
      {
          while(!s.empty() && heights[s.top()]>=heights[i])
             s.pop();
          if(s.empty())
             rightsmall[i]=n-1;
          else
             rightsmall[i]=s.top()-1;
          s.push(i);
          
      }
    //   for(int i=0;i<n;i++)
    //       cout<<leftsmall[i]<<" ";
    //   cout<<endl;
    //   for(int i=0;i<n;i++)
    //       cout<<rightsmall[i]<<" ";
    //   cout<<endl;
      int maxi=0;
      for(int i=0;i<n;i++)
      {
          maxi=max(maxi,(rightsmall[i]-leftsmall[i]+1)*heights[i]);
      }
      return maxi;
    }
};
int main() {
  vector<int> heights = {3,2,5,1,4,2};
  Solution obj;
  cout << "The largest area in the histogram is " << obj.largestRectangleArea(heights); 
  return 0;
}