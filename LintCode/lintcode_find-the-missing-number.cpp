/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        if(!nums.size())
            return 0;
        int n = nums.size();
        int ans = nums[0];
        for(int i = 1; i < n; ++ i)
            ans^=nums[i];
        for(int i = 0; i <= n; ++ i)
            ans^=i;
        return ans;
    }
};
