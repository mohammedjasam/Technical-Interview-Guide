/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2){
            return 0;
        }
        
        if(word1.size() == 0 || word2.size() == 0){
            return max(word1.size(), word2.size());
        }
        
        if(word1.size() > word2.size()){
            swap(word1, word2);
        }
        
        int lenOfWord1 = word1.size(), lenOfWord2 = word2.size();
        vector<vector<int>> dp(lenOfWord1, vector<int>(lenOfWord2, 0));
        for(int i = 0; i < lenOfWord2; ++ i){
            if(word1[0] == word2[i]){
                dp[0][i] = 1;
            } else {
                dp[0][i] = i == 0? 0 : dp[0][i - 1];
            }
        }
        
        for(int i = 1; i < lenOfWord1; ++ i){
            for(int j = 0; j < lenOfWord2; ++ j){
                if(word1[i] == word2[j]){
                    dp[i][j] = j == 0? 1 : dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int ans = lenOfWord1 + lenOfWord2 - 2*dp[lenOfWord1 - 1][lenOfWord2 - 1];
        return ans;
    }
};
