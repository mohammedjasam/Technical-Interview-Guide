/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0 || (r*c > nums.size()*nums[0].size()))
            return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        int ans_r = 0, ans_c = 0, n = nums.size(), m = nums[0].size();
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                ans[ans_r][ans_c] = nums[i][j];
                ++ ans_c;
                if(ans_c >= c){
                    ++ ans_r;
                    ans_c = 0;
                }
            }
        }
        return ans;
    }
};
