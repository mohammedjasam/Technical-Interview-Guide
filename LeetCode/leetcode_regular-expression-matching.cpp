/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/
//dp[i][j] = dp[0][0] = true
//           dp[i - 1][j - 1] where p[i] == s[j] || p[i] == '.'
//           dp[i - 2][j]  where p[i] == '*' && p[i - 1] != s[j]
//           dp[i - 2][j] (remove * ) || dp[i - 1][j] (retain p[i - 1]) || dp[i][j - 1] (repeat p[i - 1] >= 1 time(s)) where p[i] == '*' && (p[i - 1] == '.' || p[i - 1] == s[j])
//dp[lenP][lenS]
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p) {
            return true;
        }
    
        int lenOfS = s.size(), lenOfP = p.size();
        vector<vector<bool>> dp(lenOfP + 1, vector<bool>(lenOfS + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= lenOfP; ++ i){
            dp[i][0] = p[i - 1] == '*' && ( i >= 2 && dp[i - 2][0]);
        }
        
        for(int i = 1; i <= lenOfP; ++ i){
            for(int j = 1; j <= lenOfS; ++ j){
                if(p[i - 1] == s[j - 1] || p[i - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[i - 1] == '*'){
                    if(p[i - 2] == '.' || p[i - 2] == s[j - 1]) {
                        dp[i][j] = dp[i - 2][j] || dp[i - 1][j] || dp[i][j - 1];
                    } else {
                        dp[i][j] = dp[i - 2][j];
                    }
                }
            }
        }
        
        return dp[lenOfP][lenOfS];
    }
};
