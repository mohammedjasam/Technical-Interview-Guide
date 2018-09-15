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
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0)
            return nums;
        next_permutation(nums.begin(), nums.end());
        return nums;
    }
};
