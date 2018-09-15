/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        dp.clear();
        int u = 0, v = 0, w = 0;
        unordered_set<int> st;
        unordered_set<int>::iterator it;
        dp[0].insert(1);
        for(int i = 0; i < stones.size(); ++ i)
            st.insert(stones[i]);
        for(int i = 0; i < stones.size(); ++ i){
            u = stones[i];
            if(dp.find(u) == dp.end())
                continue;
            if(u == stones[stones.size() - 1])
                break;
        
            for(it = dp[u].begin(); it != dp[u].end(); ++ it){
                w = *it;
                v = u + w;
                if(st.find(v) != st.end() && v > u){
                    dp[v].insert(w - 1);
                    dp[v].insert(w);
                    dp[v].insert(w + 1);
                }
            }
        }
        return dp.find(u) != dp.end() && dp[u].size() > 0;
    }
};
