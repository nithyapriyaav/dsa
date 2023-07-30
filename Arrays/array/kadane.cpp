#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector < int > & nums) 
{
    int maxtill=nums[0];
    int final=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        maxtill=max(nums[i],nums[i]+maxtill);
        final=max(final,maxtill);
    }
    return final;
}

int main() {
  vector<int> arr{-5,-11,-3,-2};
  int lon = maxSubArray(arr);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  
}



// subarray  -- can't handle all negative numbers
#include<bits/stdc++.h>

using namespace std;
int maxSubArray(vector < int > & nums, vector < int > & subarray) 
{
    int maxtill=nums[0];
    int final=nums[0];
    int s=0;
    for(int i=1;i<nums.size();i++)
    {
        maxtill+=nums[i];
        if(maxtill<0)  
        {
            maxtill=0;
            // since negative, start from next index
            s=i+1;
        }
        if(maxtill>final)
        {
            final=maxtill;
            subarray.clear();
            subarray.push_back(s);
            subarray.push_back(i);
        }
    }
    return final;
}

int main() 
{
  vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
  vector < int > subarray;
  int lon = maxSubArray(arr, subarray);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  cout << "The subarray is " << endl;
  for (int i = subarray[0]; i <= subarray[1]; i++) 
  {
    cout << arr[i] << " ";
  }

}