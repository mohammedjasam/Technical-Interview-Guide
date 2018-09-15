/*
* Algorithm: DP
* Time complexity: O(n^2)
* Memory complexity: O(n^2)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        if(!obstacleGrid[0][0])
            dp[1][1] = 1;
        else
            dp[1][1] = 0;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                if(!obstacleGrid[i - 1][j - 1]){
                    dp[i][j] += (dp[i][j - 1] + dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
