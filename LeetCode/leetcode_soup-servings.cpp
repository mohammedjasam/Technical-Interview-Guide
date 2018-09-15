/*
*
* Tag: DP
* Time: O(n^2) ? O(1)
* Space: O(n^2) ? O(1)
*/
class Solution {
public:
    double soupServings(int N) {
        int n = N/25 + (N%25 == 0 ? 0 : 1);
        if(n >= 500){
            return 1.0;
        }
        
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
        for(int k = 0; k <= 2*n; ++ k){
            for(int i = 0; i <= n; ++ i){
                int j = k - i;
                if(j < 0 || j > n){
                    continue;
                }
                
                double ans = 0;
                if(i == 0){
                    ans = j == 0? 0.5 : 1.0;
                } else if(j > 0) {
                    ans = 0.25*(dp[floorToNonNegative(i - 4)][j] + dp[floorToNonNegative(i - 3)][floorToNonNegative(j - 1)] + dp[floorToNonNegative(i - 2)][floorToNonNegative(j - 2)] + dp[floorToNonNegative(i - 1)][floorToNonNegative(j - 3)]);
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[n][n];
    }

private:
    int floorToNonNegative(int x){
        return max(0, x);
    }
};
