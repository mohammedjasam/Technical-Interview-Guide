/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        int ans = 0;
        if(!costs.size())
            return ans;
            
        vector<int> pre(costs[0]), cur(costs[0]);
        int n = costs.size();
        for(int i = 1; i < n; ++ i){
            cur[0] = costs[i][0] + min(pre[1], pre[2]);
            cur[1] = costs[i][1] + min(pre[0], pre[2]);
            cur[2] = costs[i][2] + min(pre[0], pre[1]);
            pre = cur;
        }
        
        ans = INT_MAX;
        for(int i = 0; i < 3; ++ i)
            ans = min(ans, cur[i]);
        return ans;
    }
};
