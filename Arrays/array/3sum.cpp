#include<bits/stdc++.h>

using namespace std;
vector < vector < int >> threeSum(vector < int > & nums) 
{
    vector < vector < int >> ans;
    int left,right;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-2;i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i-1]))  /// to handle duplicates
        {
        left=i+1;
        right=nums.size()-1;
        while(left<right)
        {
            int sum=nums[left]+nums[right]+nums[i];
            if(sum==0)
           {
               vector<int> temp;
               temp.push_back(nums[i]);
               temp.push_back(nums[left]);
               temp.push_back(nums[right]);
               ans.push_back(temp);
               // to handle duplicates
               while (left < right && nums[left] == nums[left+1]) left++;
               while (left < right && nums[right] == nums[right-1]) right--;
               left++;
               right--;
            }
            else if(sum<0)
               left++;
            else
               right--;
        }
        }
    }
    return ans;
}

int main() {
   vector < int > arr{-1,0,1,2,-1,-4};
  vector < vector < int >> ans;
  ans = threeSum(arr);
  cout << "The triplets are as folleftws: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}