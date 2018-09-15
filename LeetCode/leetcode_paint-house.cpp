/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(2, vector<int>(3, 0));
        int ans = 0, n = costs.size();
        if(n == 0)
            return ans;
        ans = INT_MAX;
        for(int i = 0; i < 3; ++ i){
            dp[0][i] = costs[0][i];
        }
        for(int i = 1; i < n; ++ i){
            dp[1][0] = costs[i][0] + min(dp[0][1], dp[0][2]);
            dp[1][1] = costs[i][1] + min(dp[0][0], dp[0][2]);
            dp[1][2] = costs[i][2] + min(dp[0][0], dp[0][1]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
            dp[0][2] = dp[1][2];
        }
        for(int i = 0; i < 3; ++ i)
            ans = min(ans, dp[0][i]);
        return ans;
    }
};
