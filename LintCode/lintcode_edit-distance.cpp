/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        if(word1 == word2)
            return 0;
        if(word1 == "")
            return word2.size();
        if(word2 == "")
            return word1.size();
        int n = word1.size(), m = word2.size();
        int dp[n + 1][m + 1];
        for(int i = 0; i <= n; ++ i){
            for(int j = 0; j <= m; ++ j)
                dp[i][j] = INT_MAX;
        }
        dp[0][0] = 0;
        for(int i = 0; i <= m; ++ i){
            dp[0][i] = i;
        }
        for(int i = 0; i <= n; ++ i){
            dp[i][0] = i;
        }
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(word1[i] == word2[j])
                    dp[i + 1][j + 1] = dp[i][j];
                else{
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + 1);
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + 1);
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }
        return dp[n][m];
    }
};

