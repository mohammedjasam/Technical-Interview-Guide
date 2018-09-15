/*
*
* Tag; DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        if(prices.size() == 0)
            return 0;
        if(k>prices.size()/2)
            return QuickSolve(prices);
        vector<vector<int> > dp(2, vector<int>(k + 1));
        for(int i = 0; i < prices.size() - 1; ++ i){
            int diff = prices[i + 1] - prices[i];
            for(int j = k; j >= 1; -- j){
                dp[0][j] = max(dp[1][j - 1] + max(diff, 0), dp[0][j] + diff);
                dp[1][j] = max(dp[1][j], dp[0][j]);
            }
        }
        return dp[1][k];
    }
    
    int QuickSolve(vector<int> prices){
        int ans = 0;
        for(int i = 1; i < prices.size(); ++ i){
            if(prices[i] > prices[i - 1]){
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};
