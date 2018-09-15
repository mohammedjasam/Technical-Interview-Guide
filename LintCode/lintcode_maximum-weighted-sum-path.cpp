/*
*
* Tag: DP
* Time: O(nm)
* Space: O(m)
*/
class Solution {
public:
    int maxWeight(vector<vector<int>> &nums) {
        int n = nums.size(), m = nums[0].size();
        vector<int> dp(m, 0), predp(m, 0);
        
        dp[m - 1] = nums[0][m - 1];
        for(int i = 0; i < n; ++ i){
            for(int j = m - 1; j >= 0; -- j){
                int maxSum = dp[j];
                if(isInGrid(i, j + 1, n, m))
                    maxSum = max(maxSum, nums[i][j] + dp[j + 1]);
                if(isInGrid(i - 1, j, n, m))
                    maxSum = max(maxSum, nums[i][j] + predp[j]);
                dp[j] = maxSum;
            }
            predp = dp;
        }
        
        return dp[0];
    }
    
private:
    bool isInGrid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >=0 && j < m;
    }
};
