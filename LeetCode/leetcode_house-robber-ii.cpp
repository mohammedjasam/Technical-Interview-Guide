/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        
        return max(robHouses(nums, 0, nums.size() - 2), robHouses(nums, 1, nums.size() - 1));
    }

private:
    int robHouses(vector<int>& nums, int startIndex, int endIndex) {
        pair<int,int> dp;
        dp.first = nums[startIndex];
        dp.second = max(nums[startIndex], nums[startIndex + 1]);
        
        int ans = dp.second;
        for(int i = startIndex + 2; i <= endIndex; ++ i){
            ans = max(ans, max(dp.second, dp.first + nums[i]));
            dp.first = dp.second;
            dp.second = ans;
        }
        
        return ans;
    }
};
