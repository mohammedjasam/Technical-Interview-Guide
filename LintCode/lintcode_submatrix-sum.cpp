/*
*
* Tag: DP
* Time: O(n^4)
* Space:  O(n^2)
*/
class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        vector<vector<int>> ans;
        if(matrix.size() == 0)
            return ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i <= m; ++ i)
            dp[0][i] = 0;
        for(int i = 0; i <= n; ++ i)
            dp[i][0] = 0;
        ans.resize(2);
        vector<int> up(2), down(2);
        for(int i = 1; i <= n; ++ i){
            int sum = 0;
            for(int j = 1; j <= m; ++ j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
                sum += matrix[i - 1][j - 1];
                if(matrix[i - 1][j - 1] == 0){
                    up[0] = down[0] = i - 1;
                    up[1] = down[1] = j - 1;
                    ans[0] = up;
                    ans[1] = down;
                    return ans;
                }
                if(dp[i][j] == 0){
                    up[0] = up[1] = 0;
                    down[0] = i - 1;
                    down[1] = j - 1;
                    ans[0] = up;
                    ans[1] = down;
                    return ans;
                }
                if(sum == 0){
                    up[0] = i - 1;
                    up[1] = 0;
                    down[0] = i - 1;
                    down[1] = j - 1;
                    ans[0] = up;
                    ans[1] = down;
                    return ans; 
                }
            }
        }
        
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= m; ++ j){
                for(int k = 0; k < i; ++ k){
                    for(int l = 0; l < j; ++ l){
                        int sum = dp[i][j] - dp[k][j] - dp[i][l] + dp[k][l];
                        if(sum == 0){
                            up[0] = k;
                            up[1] = l;
                            down[0] = i - 1;
                            down[1] = j - 1;
                            ans[0] = up;
                            ans[1] = down;
                            return ans; 
                        }
                    }
                }
            }
        }
        return ans;
    }
};
