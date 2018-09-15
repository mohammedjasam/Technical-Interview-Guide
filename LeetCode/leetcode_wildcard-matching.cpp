/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm) (can be reduced to O(n))
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; ++ i){
            dp[i][0] = dp[i - 1][0] && p[i - 1] == '*';
            for(int j = 1; j <= n; ++ j){
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[i - 1] == '*') {
                    // dp[i - 1][j]: * matches empty.
                    // dp[i - 1][j]: * matches a sequence with at least one character.
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};
