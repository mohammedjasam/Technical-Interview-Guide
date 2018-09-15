/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        int ans = 0;
        if(nums.size() < 2)
            return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int gap;
        for(int i = 1; i < n; ++ i){
            gap = nums[i] - nums[i - 1];
            ans = max(ans, gap);
        }
        return ans;
    }
};
