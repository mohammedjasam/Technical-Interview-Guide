/*
* Tag: DP
* Time: O(n)
* Memory: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = -1*(1<<29);
        int sum = 0;
        for(int i = 1; i < prices.size(); i ++){
            int val = prices[i] - prices[i - 1];
            if(val >= 0){
                sum += val;
                ans = max(ans, sum);
            }else{
                if(sum + val >= 0){
                    sum += val;
                    ans = max(ans, sum);
                }else
                    sum = 0;
            }
        }
        ans = max(sum, ans);
        return ans;
    }
};

/*
*
* Tag: Math
* Time: O(n)
* Memory: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        if(prices.size() == 0){
            return ans;
        }
        
        int maxPrice = prices.back();
        for(int i = prices.size() - 2; i >= 0; -- i){
            ans = max(ans, maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        
        return ans;
    }
};
