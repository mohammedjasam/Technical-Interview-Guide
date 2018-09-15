/*
*
* Tag: DP
* Time: O(nm)
* Space: O(m)
*/
class Solution {
public:
    /*
     * @param : the prices
     * @param : the length of rod
     * @return: the max value
     */
    int cutting(vector<int>& prices, int n) {
        vector<int> dp(n + 1, 0);
        if(n == 0)
            return 0;
        for(int i = 0; i < prices.size(); ++ i){
            int rod_cut_len = i + 1;
            for(int j = 0; j <= n - rod_cut_len; ++ j){
                int rod_tot_len = j + rod_cut_len;
                dp[rod_tot_len] = max(dp[rod_tot_len], dp[j] + prices[i]);
            }
        }
        return dp[n];
    }
};
