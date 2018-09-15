/*
*
* Tag: DP
* Time: O(nk)
* Space: O(k)
*/
class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        int ans = 0;
        if(!costs.size())
            return ans;
        int n = costs.size(), k = costs[0].size();
        vector<int> cur(costs[0]);
        vector<int> minfwd(costs[0]), minbwd(costs[0]);
        
        for(int i = 1; i < k; ++ i){
            minfwd[i] = min(minfwd[i], minfwd[i - 1]);
        }
        for(int i = k - 2; i >= 0; -- i){
            minbwd[i] = min(minbwd[i], minbwd[i + 1]);
        }
        for(int i = 1; i < n; ++ i){
            for(int j = 0; j < k; ++ j){
                int val = INT_MAX;
                if(j)
                    val = min(val, minfwd[j - 1]);
                if(j < k - 1)
                    val = min(val, minbwd[j + 1]);
                cur[j] = costs[i][j] + val;
            }
            minfwd[0] = cur[0];
            for(int j = 1; j < k; ++ j){
                minfwd[j] = min(minfwd[j - 1], cur[j]);
            }
            minbwd[k - 1] = cur[k - 1];
            for(int j = k - 2; j >= 0; -- j){
                minbwd[j] = min(cur[j], minbwd[j + 1]);
            }
        }
        
        ans = INT_MAX;
        for(int i = 0; i < k; ++ i)
            ans = min(ans, cur[i]);
        return ans;
    }
};
