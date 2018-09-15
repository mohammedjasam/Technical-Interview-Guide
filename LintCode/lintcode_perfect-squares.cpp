/*
*
* Tag: DP
* Time: O(n^1.5)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        int ans = 0;
        if(!n)
            return ans;
        vector<int> dp(n + 1);
        init(dp, n);
        if(dp[n] == 1)
            return dp[n];
        for(int i = 2; i <= n; ++ i){
            if(dp[i] == 1)
                continue;
            dp[i] = i;
            for(int j = 1; j*j <= i; ++ j){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
    
private:
    void init(vector<int> &dp, int n){
        dp[0] = 0;
        
        for(int i = 1; i <= sqrt(n); ++ i){
            dp[i*i] = 1;
        }
    }
};
