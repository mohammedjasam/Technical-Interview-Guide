/*
*
* Tag: DP
* Time: O(npg)
* Space: O(pg)
*/
class Solution {
private:
    const int MOD = 1000000007;
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        if(G == 0 || group.size() == 0 || profit.size() == 0){
            return 0;
        }
        
        vector<vector<int>> dp(P + 1, vector<int>(G + 1, 0));
        dp[0][0] = 1;
        for(int k = 0; k < group.size(); ++ k){
            int g = group[k], p = profit[k];
            for(int i = P; i >= 0; -- i){
                for(int j = G - g; j >= 0; -- j){
                    int actualP = min(P, i + p);
                    dp[actualP][j + g] = (dp[actualP][j + g] + dp[i][j])%MOD;
                }
            }
        }
        
        int ans = 0;
        for(int val : dp[P]){
            ans = (ans + val)%MOD;
        }
        return ans;
    }
}; 
