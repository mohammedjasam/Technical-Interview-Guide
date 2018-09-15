/*
*
* TODO
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:
    string minWindow(string S, string T) {
        int n = T.size(), m = S.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < m; ++ i){
            if(S[i] == T[0]){
                dp[0][i] = i;
            }
        }
        
        for(int i = 1; i < n; ++ i){
            int startIndex = -1;
            for(int j = 0; j < m; ++ j){
                if(startIndex != -1 && T[i] == S[j]){
                    dp[i][j] = startIndex;
                }
                if(dp[i - 1][j] >= 0){
                    startIndex = dp[i - 1][j];
                }
            }
        }
        
        int startIndex = -1, minLen = INT_MAX;
        for(int i = 0; i < m; ++ i){
            if(dp[n - 1][i] >= 0 && i - dp[n - 1][i] + 1 < minLen){
                startIndex = dp[n - 1][i];
                minLen = i - dp[n - 1][i] + 1;
            }
        }
        
        return startIndex == -1 ? "" : S.substr(startIndex, minLen);
    }
};
