/*
*
* Tag: Greedy
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
        int ans = 0;
        if(prices.size() < 2)
            return ans;
        int n = prices.size();
        for(int i = 0; i < n - 1; ++ i){
            if(prices[i + 1] > prices[i])
                ans += (prices[i + 1] - prices[i]);
        }
        return ans;
    }
};
