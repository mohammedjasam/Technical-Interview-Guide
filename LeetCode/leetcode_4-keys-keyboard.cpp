/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1);
        if(N <= 2){
            return N;
        }
        
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 2; i <= N; ++ i){
            dp[i] = max(dp[i], i);
            
            if(i + 1 <= N){
                dp[i + 1] = max(dp[i + 1], dp[i]);
            }
            
            if(i + 2 <= N){
                dp[i + 2] = max(dp[i + 2], dp[i]);
            }
            
            int factor = 2;
            for(int j = 3; i + j <= N; ++ j){
                dp[i + j] = max(dp[i + j], factor*dp[i]);
                ++ factor;
            }
        }
        
        return dp[N];
    }
};
