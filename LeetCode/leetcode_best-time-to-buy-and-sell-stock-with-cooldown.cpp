/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/

/*
*
* dp[i]: max amount of money of ith day if:
* dp[i][0]: do nothing/cool down on ith day. dp[i][0] = max(dp[i][0], max(dp[i-1][0], dp[i-1][2]));
* dp[i][1]: buy or keep stock on ith day. dp[i][1] = max(dp[i][1], max(dp[i-1][0] - prices[i], dp[i-1][1]));
* dp[i][2]: sell stock on ith day. dp[i][1] = dp[i-1][1]+prices[i];
* ans = max(dp[n][0], dp[n][2]);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy(2, INT_MIN), empty(2, 0), sell(2, 0);
        for(int i = 0; i < prices.size(); ++ i){
            empty[i%2] = max(empty[(i + 1)%2], sell[(i + 1)%2]);
            buy[i%2] = max(buy[(i + 1)%2], empty[(i + 1)%2] - prices[i]);
            sell[i%2] = buy[(i + 1)%2] + prices[i];            
        }
        
        return max(empty[(prices.size()-1) % 2], sell[(prices.size()-1) % 2]);
    }
};
