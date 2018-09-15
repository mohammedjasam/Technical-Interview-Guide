/*
*
* Tag: DP
* Time: O(nm)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param amount: a total amount of money amount
     * @param coins: the denomination of each coin
     * @return: the number of combinations that make up the amount
     */
    int change(int amount, vector<int> &coins) {
        if(amount == 0 || coins.size() == 0)
            return 0;
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++ i){
            int curCoinValue = coins[i];
            for(int j = curCoinValue; j <= amount; ++ j){
                dp[j] += dp[j - curCoinValue];
            }
        }
        return dp[amount];
    }
};
