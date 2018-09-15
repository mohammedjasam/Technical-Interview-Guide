/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2){
            return min(cost[0], cost[1]);
        }
        
        int numOfStairs = cost.size();
        vector<int> dp(3, 0);
        for(int i = 2; i <= numOfStairs; ++ i){
            dp[2] = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
            dp[0] = dp[1], dp[1] = dp[2];
        }
        return min(dp[1], dp[2]);
    }
};
