/*
* Tag: Brute force
* Time : O(n)
* Space: O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            swap(nums[0], nums[1]);
            return ;
        }
        
        int i = n - 2;
        while(i >= 0 && nums[i + 1] <= nums[i]){
            -- i;
        }
        
        if(i >= 0){
            int j = n - 1;
            while(j > i && nums[j] <= nums[i]){
                -- j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        
        return ;
    }
};
