/*
* Tag: DP
* Time : O(n^2)
* Memory : O(n^2)
*
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2){
            return 0;
        }
        
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, INT_MAX));
        dp[0][0] = 0;
        
        for(int i = 1; i <= len2; ++ i){
            dp[0][i] = i;
        }
        for(int i = 1; i <= len1; ++ i){
            dp[i][0] = i;
        }
        
        for(int i = 0; i < len1; ++ i){
            for(int j = 0; j < len2; ++ j){
                if(word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    //add to the end of word1.substr(0, i)
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + 1);
                    //delete word1[i]
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + 1);
                    //modify word1[i] as word2[j]
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }
        
        return dp[len1][len2];
    }
};
