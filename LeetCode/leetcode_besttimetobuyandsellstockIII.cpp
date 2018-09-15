/*
* Algorithm: DP
* Time complexity: O(n)
* Memory complexity: O(n)
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1)
            return 0;
        vector<int> dp;
        int low = prices[0], maxpf = 0;
        dp.push_back(0);
        for(int i = 1; i < prices.size(); i ++){
            int tmppf = prices[i] - low;
            if(maxpf < tmppf)
                maxpf = tmppf;
            dp.push_back(maxpf);
            if(low > prices[i])
                low = prices[i];
        }
        int ans = dp[prices.size() - 1];
        int high = prices[prices.size() - 1];
        maxpf = 0;
        for(int i = prices.size() - 2; i >= 0; i --){
            int tmppf = high - prices[i];
            if(maxpf < tmppf)
                maxpf = tmppf;
            int tmpdp = dp[i] + maxpf;
            if(tmpdp > ans)
                ans = tmpdp;
            if(high < prices[i])
                high = prices[i];
        }
        return ans;
    }
};
