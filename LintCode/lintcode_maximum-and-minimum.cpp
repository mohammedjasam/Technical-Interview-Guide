/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param matrix: an input matrix 
     * @return: nums[0]: the maximum,nums[1]: the minimum
     */
    vector<int> maxAndMin(vector<vector<int>> &matrix) {
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;
        ans.resize(2);
        ans[0] = ans[1] = matrix[0][0];
        
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                ans[0] = max(ans[0], matrix[i][j]);
                ans[1] = min(ans[1], matrix[i][j]);
            }
        }
        
        return ans;
    }
};
