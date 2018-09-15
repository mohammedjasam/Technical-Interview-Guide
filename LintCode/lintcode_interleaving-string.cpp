/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if(s1.size() + s2.size() != s3.size())
            return false;
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; ++ i)
            dp[0][i] = (s2[i - 1] == s3[i - 1] && dp[0][i - 1]);
        for(int i = 1; i <= n; ++ i)
            dp[i][0] = (s1[i - 1] == s3[i - 1] && dp[i - 1][0]);
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= m; ++ j){
                dp[i][j] = ((s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || 
                            (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) );
            }
        }
        return dp[n][m];
    }
};
