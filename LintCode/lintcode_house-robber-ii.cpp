/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int previous = nums[0];
        int current = max(nums[0], nums[1]);
        for (int i = 2; i <= n - 2; i++) {
            int tmp = current;
            current = max(previous + nums[i], current);
            previous = tmp;
        }
        int maxInPreviousHalf = current;
        previous = nums[1];
        current = max(nums[1], nums[2]);
        for (int i = 3; i <= n - 1; i++) {
            int tmp = current;
            current = max(previous + nums[i], current);
            previous = tmp;
        }
        return max(maxInPreviousHalf, current);
    }
};
