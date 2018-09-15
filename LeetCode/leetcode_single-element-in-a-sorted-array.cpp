/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int l = 0, r = nums.size() - 1, ans, mid = 0;
        while(l <= r){
            if(l == r){
                ans = nums[l];
                break;
            }
            mid = (l + r)>>1;
            if(nums[mid] == nums[mid - 1]){
                if((mid - l + 1)%2 == 1)
                    r = mid;
                else
                    l = mid + 1;
            }else if(nums[mid] == nums[mid + 1]){
                if((mid - l)%2 == 0)
                    l = mid;
                else
                    r = mid - 1;
            }else{
                ans = nums[mid];
                break;
            }
        }
        return ans;
    }
};
