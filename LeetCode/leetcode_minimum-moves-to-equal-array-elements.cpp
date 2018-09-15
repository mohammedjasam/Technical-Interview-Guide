/*
*
* Tag: Math
* Time:O(n)
* Space:O(1)
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 0)
            return ans;
        int minval = INT_MAX;
        for(int i = 0; i < nums.size(); ++ i)
            minval = min(minval, nums[i]);
        for(int i = 0; i < nums.size(); ++ i)
            ans += (nums[i] - minval);
        return ans;
    }
};
