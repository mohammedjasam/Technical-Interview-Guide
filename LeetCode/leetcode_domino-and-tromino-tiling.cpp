/*
*
* Better Solution
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
private:
    const int MOD = 1000000007;
public:
    int numTilings(int N) {
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= N; ++ i){
            for(int j = 1; j <= i; ++ j){
                dp[i] += (dp[i - j]*(j <= 2 ? 1 : 2))%MOD;
                dp[i] %= MOD;
            }
        }
        
        return dp[N];
    }
};
