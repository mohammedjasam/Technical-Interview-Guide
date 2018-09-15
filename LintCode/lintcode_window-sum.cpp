/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        vector<int> ans;
        if(nums.size() == 0 || k == 0)
            return ans;
            
        int n = nums.size();
        if(nums.size() <= k)
            ans.resize(1);
        else
            ans.resize(n - k + 1);
        
        int sum = 0;
        int idx = 0, curAnsIdx = 0;
        for(idx = 0; idx < k && idx < n; ++ idx){
            sum += nums[idx];
        }
        ans[curAnsIdx ++] = sum;
        
        for(; idx < n; ++ idx, ++ curAnsIdx) {
            sum = (sum - nums[idx - k] + nums[idx]);
            ans[curAnsIdx] = sum;
        }
        
        return ans;
    }
};
