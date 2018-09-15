/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        if(nums.size() <= 2)
            return (int)nums.size();
        dp[0][0] = dp[0][1] = 1;
        int ans = 0;
        for(int i = 1; i < nums.size(); ++ i){
            dp[i][0] = dp[i][1] = 1;
            for(int j = 0; j < i; ++ j){
                if(nums[i] == nums[j]){
                    dp[i][0] = max(dp[i][0], dp[j][0]);
                    dp[i][1] = max(dp[i][1], dp[j][1]);
                }else if(nums[i] > nums[j]){
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                    dp[i][1] = max(dp[i][1], dp[j][1]);
                }else{
                    dp[i][0] = max(dp[i][0], dp[j][0]);
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};

/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 2)
            return (int)nums.size();
        int ans = 1;
        int i = 1;
        while(i < nums.size() && nums[i] == nums[i - 1]) ++ i;
        if(i >= nums.size())
            return ans;
        bool increase = nums[i] > nums[i - 1];
        while(i < nums.size()){
            if(increase){
                while(i + 1 < nums.size() && nums[i + 1] >= nums[i]) ++ i;
            }else{
                while(i + 1 < nums.size() && nums[i + 1] <= nums[i]) ++ i;
            }
            increase = increase?false:true;
            ++ ans;
            ++ i;
        }
        return ans;
    }
};
