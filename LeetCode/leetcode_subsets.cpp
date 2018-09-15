/*
*
* Tag: Bit Manipulation
* Time: O(2^n)
* Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0)
            return ans;
        int n = nums.size();
        int m = (1<<n), idx = 0;
        ans.resize(m);
        for(int i = 0; i < m; ++ i){
            ans[idx ++] = getSubset(i, nums);
        }
        return ans;
    }
private:
    inline vector<int> getSubset(int v, vector<int> &nums){
        vector<int> res;
        if(v == 0)
            return res;
        int i = 0;
        while(v){
            if((v&1) == 1)
                res.push_back(nums[i]);
            v >>= 1;
            ++ i;
        }
        return res;
    }
};
