// using  sort()
int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
        // kth minimum
        // int n=nums.size();
        // cout<<nums[n-k];
    }


// using  priority_queue(min heap)
int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> pq;
        for(int num:nums)
        {
            pq.push(num);
// minimum values will be removed.
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }