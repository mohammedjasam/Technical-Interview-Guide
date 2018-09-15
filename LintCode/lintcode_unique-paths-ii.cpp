/*
*
* Tag: DP
* Time: O(mn)
* Space: O(mn)
*/
class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if(obstacleGrid.size() == 0)
            return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        if(obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        else
            dp[0][0] = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(!i && !j)
                    continue;
                if(obstacleGrid[i][j])
                    continue;
                if(i - 1 >= 0)
                    dp[i][j] += dp[i - 1][j];
                if(j - 1 >= 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};
