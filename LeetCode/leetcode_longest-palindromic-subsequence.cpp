/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0)
            return 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for(int i = n - 2; i >= 0; -- i){
            for(int j = i + 1; j < n; ++ j){
                if(s[i] == s[j]){
                    dp[i][j] = j == i + 1 ? 2 : max(dp[i][j], dp[i + 1][j - 1] + 2);
                }
                dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));
            }
        }
        return dp[0][n - 1];
    }
};
