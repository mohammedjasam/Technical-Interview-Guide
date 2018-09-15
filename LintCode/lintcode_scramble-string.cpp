/*
*
* Tag: DP
* Time: O(n^3)
* Space: O(n^3)
*/
class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        if(s1.size() != s2.size())
            return false;
        const int N = s1.size();
        bool dp[N + 1][N][N];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < N; ++ i){
            for(int j = 0; j < N; ++ j){
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for(int n = 1; n <= N; ++ n){
            for(int i = 0; i + n <= N; ++ i){
                for(int j = 0; j + n <= N; ++ j){
                    for(int k = 1; k < n; ++ k){
                        if((dp[k][i][j] && dp[n - k][i + k][j + k]) 
                        || (dp[k][i][j + n - k] && dp[n - k][i + k][j])){
                            dp[n][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[N][0][0];
    }
};
