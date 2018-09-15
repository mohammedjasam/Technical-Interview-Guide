/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.size() == 0)
            return 0;
        int ans = 0, sum = 0;
        int n = prices.size();
        for(int i = 0; i < n - 1; ++ i){
            sum += (prices[i + 1] - prices[i]);
            ans = max(sum, ans);
            if(sum < 0)
                sum = 0;
        }
        return ans;
    }
};

