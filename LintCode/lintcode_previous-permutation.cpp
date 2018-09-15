/*
*
* Tag: ?
* Time: ?
* Space: ?
*/
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0)
            return nums;
        prev_permutation(nums.begin(), nums.end());
        return nums;
    }
};
