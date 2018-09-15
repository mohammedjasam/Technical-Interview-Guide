/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int ans = 0;
        if(S.size() < T.size())
            return ans;
        if(S == T)
            return 1;
        int n = S.size(), m = T.size();
        int dp[n][m];
        
        dp[0][0] = (S[0] == T[0])?1:0;
        for(int i = 1; i < n; ++ i){
            dp[i][0] = dp[i - 1][0];
            if(T[0] == S[i]){
                ++ dp[i][0];
            }
        }
        
        for(int i = 1; i < m; ++ i){
            dp[i][i] = ((S[i] == T[i]? dp[i - 1][i - 1] : 0));
            for(int j = i + 1; j < n; ++ j){
                dp[j][i] = dp[j - 1][i];
                if(T[i] == S[j])
                    dp[j][i] += dp[j - 1][i - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
    
};

