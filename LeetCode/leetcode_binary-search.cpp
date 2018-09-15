/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0 || nums.front() > target || nums.back() < target) {
            return -1;
        }
        
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r)>>1;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
};
