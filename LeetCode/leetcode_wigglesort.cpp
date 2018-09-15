/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return ;
        int n = nums.size();
        for(int i = 1; i < n; i += 2){
            if(nums[i - 1] > nums[i])
                swap(nums[i - 1], nums[i]);
            if(i + 1 < n && nums[i + 1] > nums[i])
                swap(nums[i + 1], nums[i]);
        }
        return ;
    }
};
