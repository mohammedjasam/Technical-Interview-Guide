/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(lgn)
*/
class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        int ans = 0;
        if(!A.size())
            return ans;
        int n = A.size(), m = A[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                ans = max(ans, dfs(i, j, n, m, A, dp));
            }
        }
        return ans;
    }
    
    int dfs(int sta_x, int sta_y, int n, int m, vector<vector<int>> &A, vector<vector<int>> &dp){
        if(dp[sta_x][sta_y])
            return dp[sta_x][sta_y];
        for(int i = 0; i < 4; ++ i){
            int x = sta_x + dir[i][0], y = sta_y + dir[i][1];
            if(x >= 0 && x < n && y >= 0 && y < m && A[sta_x][sta_y] < A[x][y]){
                dp[sta_x][sta_y] = max(dp[sta_x][sta_y], dfs(x, y, n, m, A, dp));
            }
        }
        return ++ dp[sta_x][sta_y];
    }

private:
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
};
