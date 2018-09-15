/*
*
* Tag: DP && Data Structure
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        int ans = 0;
        if(matrix.size() == 0)
            return ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m + 1));
        for(int i = 0; i < m; ++ i){
            int sum = 0;
            for(int j = 0; j < n; ++ j){
                if(!matrix[j][i])
                    sum = 0;
                else
                    ++ sum;
                dp[j][i] = sum;
            }
        }
        for(int i = 0; i < n; ++ i){
            stack<int> stk;
            dp[i][m] = 0;
            for(int j = 0; j <= m; ){
                if(stk.empty() || dp[i][j] > dp[i][stk.top()]){
                    stk.push(j ++);
                } else {
                    int id = stk.top();
                    stk.pop();
                    ans = max(ans, dp[i][id]*(stk.empty()?j:j - stk.top() - 1));
                }
            }
        }
        return ans;
    }
};
