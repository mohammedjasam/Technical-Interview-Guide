/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        if(nums.size() <= 1)
            return ;
        int n = nums.size();
        for(int i = 1; i < n; i += 2){
            if(nums[i] < nums[i - 1])
                swap(nums[i], nums[i - 1]);
            if(i + 1 < n && nums[i] < nums[i + 1])
                swap(nums[i], nums[i + 1]);
        }
    }
};
