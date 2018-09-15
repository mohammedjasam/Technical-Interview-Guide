/*
*
* Tag: DP
* Time: O(n^3)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
                int ans = 0;
        if(matrix.size() == 0)
            return ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i < n; ++ i){
            int sum = 0;
            for(int j = 0; j < m; ++ j){
                if(!matrix[i][j])
                    sum = 0;
                else
                    ++ sum;
                dp[i][j] = sum;
            }
        }
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(dp[i][j]){
                    int k = i;
                    int area = 0, len = m;
                    while(k>=0 && dp[k][j]){
                        len = min(len, dp[k][j]);
                        if(len*len < area)
                            break;
                        area = max(area, min(len, i + 1 - k)*min(len, i + 1 - k));
                        -- k;
                    }
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
