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
        
        pair<int,int> dp;
        dp.first = nums[0];
        dp.second = max(nums[0], nums[1]);
        
        int ans = 0;
        for(int i = 2; i < nums.size(); ++ i){
            ans = max(ans, max(dp.second, dp.first + nums[i]));
            dp.first = dp.second;
            dp.second = ans;
        }
        
        return ans;
    }
};
