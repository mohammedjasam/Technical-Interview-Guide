/*
*
* Tag: DP
* Time: O(n*sum)
* Space: O(sum)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++ i)
            sum += nums[i];
        if(sum%2 == 1)
            return false;
        int bnd = sum/2;
        vector<bool> dp(sum/2+1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); ++ i){
            for(int j = bnd; j >= nums[i]; -- j){
                if(dp[j - nums[i]])
                    dp[j] = 1;
                if(dp[bnd])
                    return true;
            }
        }
        return dp[bnd];
    }
};
