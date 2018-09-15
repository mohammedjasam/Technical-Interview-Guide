/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target <= nums[0]) {
            return 0;
        }
        if(target > nums.back()){
            return nums.size();
        }
        
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r)>>1;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
};
