/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        if(s.size() == 0){
            return ans;
        }
        
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i = len - 1; i >= 0; -- i){
            dp[i][i] = true;
            ++ ans;
            for(int j = i + 1; j < len; ++ j){
                if(s[i] == s[j] && (j == i + 1 || dp[i + 1][j - 1] ) ) {
                    ++ ans;
                    dp[i][j] = true;
                }
            }
        }
        
        return ans;
    }
};
