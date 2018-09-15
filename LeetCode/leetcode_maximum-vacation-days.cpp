/*
*
* Tag: DP
* Time: O(kn^2)
* Space: O(n)
*/
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int ans = 0;
        if(days.size() == 0 || flights.size() == 0){
            return ans;
        }
        
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> dp(2, vector<int>(n, -1));
        
        dp[0][0] = 0;
        for(int i = 1; i <= k; ++ i){
            for(int j = 0; j < n; ++ j){
                if(dp[(i-1)%2][j] == -1){
                    continue;
                }
                
                dp[i%2][j] = max(dp[i%2][j], dp[(i - 1)%2][j] + days[j][i - 1]);
                for(int f = 0; f < n; ++ f){
                    if(flights[j][f] == 0){
                        continue;
                    }
                    
                    dp[i%2][f] = max(dp[i%2][f], dp[(i - 1)%2][j] + days[f][i - 1]);
                }
            }
            
            fill(dp[(i - 1)%2].begin(), dp[(i - 1)%2].end(), -1);
        }
        
        int weekIndex = k%2;
        for(int i = 0; i < n; ++ i){
            ans = max(ans, dp[weekIndex][i]);
        }
        return ans;
    }
};
