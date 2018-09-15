/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /*
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> ans(2, 0);
        if(isGivenNumArrayInValid(nums, target))
            return ans;
        int fwd_idx = 0, bwd_idx = nums.size() - 1;
        for(; fwd_idx < bwd_idx;){
            long long two_sum = (long long)nums[fwd_idx] + (long long)nums[bwd_idx];
            if(two_sum > target)
                -- bwd_idx;
            else if(two_sum < target)
                ++ fwd_idx;
            else {
                updateAnswerVector(ans, fwd_idx, bwd_idx);
                break;
            }
        }
        return ans;
    }
private:
    bool isGivenNumArrayInValid(vector<int> &nums, int target){
        return nums.size() < 2 || nums[0] > target;
    }
    
    int updateAnswerVector(vector<int> &ans, int fwd_idx, int bwd_idx){
        ans[0] = fwd_idx + 1, ans[1] = bwd_idx + 1;
    }
};
