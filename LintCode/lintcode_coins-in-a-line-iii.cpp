/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        if(!n)
            return false;
        vector<vector<int>> dp(n, vector<int>(n)), sum(n, vector<int>(n));
        for(int i = 0; i < n; ++ i){
            dp[i][i] = values[i];
            sum[i][i] = values[i];
            for(int j = i + 1; j < n; ++ j){
                sum[i][j] = sum[i][j - 1] + values[j];
            }
        }
        for(int i = 1; i < n; ++ i){
            for(int j = 0; j < n - i; ++ j){
                dp[j][j + i] = sum[j][j + i] - min(dp[j + 1][j + i], dp[j][j + i - 1]);
            }
        }
        return dp[0][n - 1] > (sum[0][n - 1]/2);
    }
};
