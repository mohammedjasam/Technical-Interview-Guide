/*
*
* Tag: DP
* Time: O(Nnm)
* Space: O(Nnm)
*/
class Solution {
private:
    const int MOD = 1000000007;
public:
    int findPaths(int m, int n, int N, int i, int j) {
        uint dp[51][50][50] = {};
        for(int k = 1; k <= N; ++ k){
            for(int r = 0; r < m; ++ r){
                for(int c = 0; c < n; ++ c){
                    dp[k][r][c] = ( (r == 0 ? 1 : dp[k - 1][r - 1][c]) + (r == m - 1 ? 1 : dp[k - 1][r + 1][c]) + (c == 0 ? 1 : dp[k - 1][r][c - 1]) + (c == n - 1 ? 1 : dp[k - 1][r][c + 1]) )%MOD;
                }
            }
        }
        
        return dp[N][i][j];
    }
};
