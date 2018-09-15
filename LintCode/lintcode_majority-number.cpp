/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if(nums.size() <= 2)
            return nums[0];
        int k = nums.size()/2;
        int ans = partition(nums,k);
        return ans;
    }
    
    int partition(vector<int> nums, int k){
        int start = 0, end = nums.size() - 1;
        int ans;
        while(1){
            int pivot = nums[end];
            int tpos = start - 1;
            for(int i = start; i < end; ++ i){
                if(nums[i] < pivot)
                    swap(nums[i], nums[++ tpos]);
            }
            swap(nums[++ tpos], nums[end]);
            if(tpos == k){
                ans = nums[tpos];
                break;
            }else if(tpos > k){
                end = tpos - 1;
            }else{
                start = tpos + 1;
            }
        }
        return ans;
    }
};

