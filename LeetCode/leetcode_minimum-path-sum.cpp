/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = grid.size(), n = grid[0].size();
        int dp[m + 10][n + 10];
        for(int i = 0; i < m + 10; i ++){
            for(int j = 0; j < n + 10; j ++){
                dp[i][j] = (1 << 25);
            }
        }
        dp[0][0] = 0;
        dp[1][1] = grid[0][0];
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                dp[i][j] = min(dp[i][j],dp[i - 1][j] + grid[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j],dp[i][j - 1] + grid[i - 1][j - 1]);
            }
        }
        return dp[m][n];
    }
};
