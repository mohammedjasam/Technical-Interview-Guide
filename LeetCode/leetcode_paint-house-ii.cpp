/*
*
* Tag: DP
* Time: O(nk)
* Space: O(k)
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int ans = 0;
        if(costs.size() == 1 && costs[0].size() == 1)
            return costs[0][0];
        if(costs.size() == 0 || costs[0].size() <= 1)
            return ans;
            
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(2, vector<int>(k));
        ans = INT_MAX;
        for(int i = 0; i < k; ++ i)
            dp[0][i] = costs[0][i];
            
        vector<int> min_val(2);
        for(int i = 1; i < n; ++ i){
            for(int j = 0; j < k; ++ j){
                if(!j){
                    min_val[0] = dp[0][0];
                    min_val[1] = INT_MAX;
                }else{
                    if(min_val[0] > dp[0][j]){
                        min_val[1] = min_val[0];
                        min_val[0] = dp[0][j];
                    }else if(min_val[1] > dp[0][j]){
                        min_val[1] = dp[0][j];
                    }
                }
            }
            
            for(int j = 0; j < k; ++ j){
                if(dp[0][j] == min_val[0])
                    dp[1][j] = costs[i][j] + min_val[1];
                else
                    dp[1][j] = costs[i][j] + min_val[0];
            }
            
            for(int j = 0; j < k; ++ j){
                dp[0][j] = dp[1][j];
            }
        }
        for(int i = 0; i < k; ++ i)
            ans = min(ans, dp[0][i]);
        return ans;
    }
};
