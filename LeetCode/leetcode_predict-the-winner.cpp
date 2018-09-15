/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0)), sum(n, vector<long long>(n, 0));
        for(int i = 0; i < n; ++ i){
            dp[i][i] = sum[i][i] = nums[i];
            for(int j = i + 1; j < n; ++ j)
                sum[i][j] = sum[i][j - 1] + nums[j];
        }
        for(int i = 1; i < n; ++ i){
            for(int j = 0; j < n - i; ++ j){
                dp[j][j + i] = sum[j][j + i] - min(dp[j][j + i - 1], dp[j + 1][j + i]);
            }
        }
        return dp[0][n - 1] >= (sum[0][n - 1]%2?(sum[0][n - 1]+1)/2:sum[0][n - 1]/2);
    }
};
