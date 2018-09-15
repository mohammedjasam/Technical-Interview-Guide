/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int ans = 0;
        if(!nums.size())
            return ans;
        ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; ++ i)
            nums[i] = -nums[i];
        int sum = 0;
        for(int i = 0; i < n; ++ i){
            if(sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            ans = max(ans, sum);
        }
        return -ans;
    }
};
