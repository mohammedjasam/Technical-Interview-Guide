/*
*
* Tag: DFS
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int ans = 0;
        if(M.size() == 0)
            return ans;
        int n = M.size(), m = M[0].size();
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4,0)));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(M[i][j] == 1){
                    for(int k = 0; k < 4; ++ k){
                        if(dp[i][j][k] == 0){
                            int sum = 1;
                            dfs(i, j, k, sum, n, m, M, dp);
                        }
                        ans = max(dp[i][j][k], ans);
                    }
                }
            }
        }
        return ans;
    }
private:
    void dfs(int r, int c, int k, int sum, int n, int m, vector<vector<int>>& M, vector<vector<vector<int>>> &dp){
        int nr = r + dir[k][0], nc = c + dir[k][1];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m){
            if(M[nr][nc] == 1 && dp[nr][nc][k] == 0){
                dfs(nr, nc, k, sum, n, m, M, dp);
            }
            dp[r][c][k] = dp[nr][nc][k] + 1;
        }else
            dp[r][c][k] = 1;
    }
private:
    int dir[4][2] = {{0,1},{1,1},{1,0},{1,-1}};
};
