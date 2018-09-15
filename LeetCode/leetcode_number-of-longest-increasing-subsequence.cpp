/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 0){
            return ans;
        }
        
        int n = nums.size();
        int lengthOfLongestSubsequence = 1;
        vector<pair<int,int>> dp(n);
        for(int i = 1; i < n; ++ i){
            dp[i] = make_pair(1, 1);
            for(int j = 0; j < i; ++ j){
                if(nums[i] > nums[j]) {
                    if(dp[j].first + 1 > dp[i].first){
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    } else if(dp[j].first + 1 == dp[i].first){
                        dp[i].second += dp[j].second;
                    }
                }
            }
            lengthOfLongestSubsequence = max(lengthOfLongestSubsequence, dp[i].first);
        }
        
        for(int i = 0; i < n; ++ i){
            if(dp[i].first == lengthOfLongestSubsequence){
                ans += dp[i].second;
            }
        }
        
        return ans;
    }
};
