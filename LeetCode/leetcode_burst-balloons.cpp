/*
*
* Tag: DP
* Time: O(n^3)
* Space: O(n^2)
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int len = 1; len <= n; ++ len){
            for(int start = 1; start <= n - len + 1; ++ start){
                int end = start + len - 1;
                for(int i = start; i <= end; ++ i){
                    dp[start][end] = max(dp[start][end], dp[start][i - 1] + nums[start - 1]*nums[i]*nums[end + 1] + dp[i + 1][end]);
                }
            }
        }
        
        return dp[1][n];
    }
};
