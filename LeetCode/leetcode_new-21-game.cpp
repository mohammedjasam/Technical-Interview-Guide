/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) {
            return 1.0;
        }
        
        double ans = 0;
        double P = 1.0/((double)W);
        double pSum = 1.0;
        vector<double> dp(N + 1, 0);
        dp[0] = 1.0;
        for(int i = 1; i <= N; ++ i){
            dp[i] = pSum*P;
            if(i < K) {
                pSum += dp[i];
            } else {
                ans += dp[i];
            }
            
            if(i >= W){
                pSum -= dp[i - W];
            }
        }
        
        return ans;
    }
};
