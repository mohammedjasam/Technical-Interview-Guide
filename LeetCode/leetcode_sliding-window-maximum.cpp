/*
*
* Tag: Data Structure (Deque, Monotonic Queue)
* Time: O(n)
* Space: O(k)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0 || k == 0)
            return ans;
        deque<int> dq;
        int n = nums.size(), idx = 0;
        if(n <= k)
            ans.resize(1);
        else
            ans.resize(n - k + 1);
        for(int i = 0; i < n; ++ i){
            if(!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                ans[idx ++] = nums[dq.front()];
        }
        return ans;
    }
};
