/*
*
* Tag: DP
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<int> ans;
        if(!nums.size())
            return ans;
        int n = nums.size();
        ans.resize(2);
        ans[0] = ans[1] = 0;
        if(n == 1)
            return ans;
        vector<pair<int,int>> dp(n+1, make_pair(0,0));
        
        dp[0].second = -1;
        for(int i = 0; i < n; ++ i){
            dp[i + 1].first = dp[i].first + nums[i];
            dp[i + 1].second = i;
        }
        
        sort(dp.begin(), dp.end());
        
        int minval = INT_MAX;
        for(int i = 1; i <= n; ++ i){
            int tmp = abs(dp[i].first - dp[i - 1].first);
            if(tmp >= minval)
                continue;
            minval = tmp;
            ans[0] = min(dp[i].second, dp[i - 1].second) + 1;
            ans[1] = max(dp[i].second, dp[i - 1].second);
        }
        
        return ans;
    }
};
