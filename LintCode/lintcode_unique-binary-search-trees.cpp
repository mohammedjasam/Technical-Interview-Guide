/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if(!n)
            return 1;
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++ i){
            dp[i] = 0;
            for(int j = 1; j<= i; ++ j){
                dp[i] += dp[j - 1]*dp[i - j];
            }
        }
        return dp[n];
    }
};
