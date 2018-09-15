/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm) (can be reduced to O(min(n, m)))
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSize = 0;
        for(int i = 0; i < n; ++ i){
            dp[i][0] = matrix[i][0] - '0';
            maxSize = max(maxSize, dp[i][0]);
        }
        
        for(int i = 0; i < m; ++ i){
            dp[0][i] = matrix[0][i] - '0';
            maxSize = max(maxSize, dp[0][i]);
        }
        
        for(int i = 1; i < n; ++ i){
            for(int j = 1; j < m; ++ j){
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }
        
        return maxSize*maxSize;
    }
};
