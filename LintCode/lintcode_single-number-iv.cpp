/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: The number array
     * @return: Return the single number
     */
    int getSingleNumber(vector<int> &nums) {
        return nums.size() == 1? nums[0] : binarySearch(nums);
    }
    
private:
    int binarySearch(vector<int> &nums){
        int left = 0, right = nums.size() - 1;
        
        while(left < right) {
            int mid = ((right - left)>>1) + left;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if(nums[mid] == nums[mid + 1]){
                if((mid - left)%2 == 1)
                    right = mid - 1;
                else
                    left = mid + 2;
            }else{
                if((mid - left)%2 == 1)
                    left = mid + 1;
                else
                    right = mid - 2;
            }
        }
        
        return nums[left];
    }
};
