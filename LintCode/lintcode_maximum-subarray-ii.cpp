/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        vector<int> dp(nums.size());
        if(nums.size() == 0)
            return 0;
        dp[0] = nums[0];
        int sum = nums[0], maxval = INT_MIN;
        maxval = max(maxval, sum);
        for(int i = 1; i < nums.size(); i ++){
            if(sum < 0 )
                sum = nums[i];
            else
                sum += nums[i];
            maxval = max(sum, maxval);
            dp[i] = maxval;
        }
        sum = nums[nums.size() - 1];
        int ans = INT_MIN;
        maxval = INT_MIN;
        maxval = max(sum, maxval);
        for(int i = nums.size() - 2; i >= 0; i --){
            ans = max(dp[i] + maxval, ans);
            if(sum < 0 )
                sum = nums[i];
            else
                sum += nums[i];
            maxval = max(maxval, sum);
        }
        return ans;
    }
};
