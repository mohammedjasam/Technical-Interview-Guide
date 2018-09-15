/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int ans = 0;
        if(!A.size() || !B.size())
            return ans;
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0] = 0;
        for(int i = 0; i < n; ++ i){
            if(A[i] == B[0]){
                dp[i + 1][1] = 1;
                ans = max(ans, dp[i + 1][1]);
            }
        }
        for(int i = 0; i < m; ++ i){
            if(B[i] == A[0]){
                dp[1][i + 1] = 1;
                ans = max(ans, dp[1][i + 1]);
            }
        }
        for(int i = 1; i < m; ++ i){
            for(int j = 1; j < n; ++ j){
                dp[j + 1][i + 1] = 0;
                if(A[j] == B[i]){
                    dp[j + 1][i + 1] = dp[j][i] + 1;
                    ans = max(ans, dp[j + 1][i + 1]);
                }
            }
        }
        return ans;
    }
};

