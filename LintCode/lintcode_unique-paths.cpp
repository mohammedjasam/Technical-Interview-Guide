/*
*
* Tag: DP (or Math)
* Time: O(mn) (Best: O(m))
* Space: O(mn) (Best: O(1))
*/
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if(m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int i = 0; i < m; ++ i){
            for(int j = 0; j < n; ++ j){
//                dp[i][j] = 0;
                if(i - 1 >= 0)
                    dp[i][j] += dp[i - 1][j];
                if(j - 1 >= 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

