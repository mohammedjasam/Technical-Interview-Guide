/*
*
* Tag: DP
* Time: O(max(nlgn, mn)) where m = target number
* Space: O(m)
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        if(!nums.size() || !target) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        dp[0] = 1;
        for(int i = 1; i <= target; ++ i){
            for(int j = 0; j < nums.size() && nums[j] <= i; ++ j){
                dp[i] += dp[i - nums[j]];
            }
        }
        
        return dp[target];
    }
};
