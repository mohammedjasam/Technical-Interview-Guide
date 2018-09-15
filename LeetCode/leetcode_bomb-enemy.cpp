/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int ans = 0;
        if(!grid.size()){
            return ans;
        }
        
        int dp[grid.size() + 2][grid[0].size() + 2][4];     
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                if(grid[i][j] == 'W')
                    dp[i + 1][j + 1][0] = dp[i + 1][j + 1][1] = 0;
                else if(grid[i][j] == '0'){
                    dp[i + 1][j + 1][0] = dp[i + 1][j][0];
                    dp[i + 1][j + 1][1] = dp[i][j + 1][1];
                }else{
                    dp[i + 1][j + 1][0] = dp[i + 1][j][0] + 1;
                    dp[i + 1][j + 1][1] = dp[i][j + 1][1] + 1;
                }
            }
        }
        
        for(int i = grid.size() - 1; i >= 0; -- i){
            for(int j = grid[0].size() - 1; j >= 0; -- j){
                if(grid[i][j] == 'W')
                    dp[i + 1][j + 1][0] = dp[i + 1][j + 1][1] = 0;
                else if(grid[i][j] == '0'){
                    dp[i + 1][j + 1][2] = dp[i + 1][j + 2][2];
                    dp[i + 1][j + 1][3] = dp[i + 2][j + 1][3];
                }else{
                    dp[i + 1][j + 1][2] = dp[i + 1][j + 2][2] + 1;
                    dp[i + 1][j + 1][3] = dp[i + 2][j + 1][3] + 1;
                }
            }
        }
        
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                if(grid[i][j] == '0'){
                    ans = max(ans, dp[i + 1][j + 1][0] + dp[i + 1][j + 1][1] + dp[i + 1][j + 1][2] + dp[i + 1][j + 1][3]);
                }
            }
        }
        
        return ans;
    }
};
