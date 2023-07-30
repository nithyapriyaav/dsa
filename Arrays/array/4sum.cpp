#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) 
    {
         vector<vector<int> > res;
        
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n-3; i++) 
        {
            if(i==0 || (i>0 && num[i]!=num[i-1]))
            {
            for (int j = i+1; j < n-2; j++) 
            {
                 if(j==1 || (j>1 && num[j]!=num[j-1]))
               {
                int target_2 = target - (num[i]+num[j]);
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) 
                {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else 
                    {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == num[front+1]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == num[back-1]) --back;
                        front++;
                        back--;
                
                    }
                }
               }
            }
            }
        }
    
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> v{1,-2,0,-1,0,-2,2};
    
    vector<vector<int>> sum=obj.fourSum(v,0);
    cout<<"The unique quadruplets are"<<endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}