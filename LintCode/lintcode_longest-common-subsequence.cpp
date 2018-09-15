/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if(A=="" || B=="")
            return 0;
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0] = 0;
//        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(A[i] == B[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[n][m];
    }
};

