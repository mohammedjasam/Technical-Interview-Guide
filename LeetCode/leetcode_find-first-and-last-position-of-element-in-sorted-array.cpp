/*
*
* TODO
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if(nums.size() == 0){
            return ans;
        } else {
            int lval = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
            int rval = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
            if(lval >= nums.size() || nums[lval] != target){
                return ans;
            } else {
                ans[0] = lval, ans[1] = rval;
                return ans;
            }
        }
    }
};
