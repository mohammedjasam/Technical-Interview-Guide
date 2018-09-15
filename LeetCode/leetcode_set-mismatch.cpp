/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        if(nums.size() < 1) {
            return ans;
        }
        
        for(int i = 0; i < nums.size(); ++ i) {
            while(nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i < nums.size(); ++ i) {
            if(nums[i] != i + 1) 
                return {nums[i], i + 1};
        }
        
        return ans;
    }
};
