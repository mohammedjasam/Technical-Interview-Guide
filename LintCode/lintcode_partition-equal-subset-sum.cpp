/*
*
* Tag: DP
* Time: O(n*sum)
* Space: O(sum)
*/
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int totSum = 0;
        for(int i = 0; i < nums.size(); ++ i)
            totSum += nums[i];
            
        if(totSum%2 != 0)
            return false;
        
        int partitionSum = (totSum >> 1);
        vector<bool> dp(partitionSum + 1, false);
        
        dp[0] = true;
        for(int i = 0; i < nums.size(); ++ i) {
            int curNum = nums[i];
            for(int j = partitionSum; j >= curNum; -- j){
                dp[j] = (dp[j] | dp[j - curNum]);
            }
            
            if(dp[partitionSum])
                return true;
        }
        
        return false;
    }
};
