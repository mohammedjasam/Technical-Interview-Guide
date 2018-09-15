/*
*
* Tag: DP
* Time: O(n^1.5)
* Space: O(n)
*/
class Solution {
public:
    int minSteps(int n) {
        if(n == 0){
            return n;
        }
        
        vector<int> dp(n + 1, n);
        dp[1] = 0;
        for(int i = 2; i <= n; ++ i){
            dp[i] = min(dp[i], i);
            
            for(int j = 2; j*j <= i; ++ j){
                if(i%j == 0){
                    dp[i] = min(dp[i], dp[j] + i/j);
                    dp[i] = min(dp[i], dp[i/j] + j);
                }
            }
        }
        
        return dp[n];
    }
};
