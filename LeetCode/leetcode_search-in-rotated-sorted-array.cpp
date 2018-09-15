/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0){
            return -1;
        }
        
        int l = 0, r = n - 1;
        if(nums[l] == target){
            return l;
        }
        
        if(nums[r] == target){
            return r;
        }
        
        while(l <= r){
            int mid = (l + r)>>1;
            if(nums[mid] == target)
                return mid;
            if(nums[l] <= nums[mid]){
                if(nums[mid] > target && target >= nums[l])
                    r = mid;
                else
                    l = mid + 1;
            }else{
                if(target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        
        return -1;
    }
};
