/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if(!nums.size()){
            return ans;
        }
        
        int maxsize = 1, maxid = 0;
        vector<int> dp(nums.size()), prev(nums.size());
        for(int i = 0; i < nums.size(); ++ i){
            dp[i] = 1;
            prev[i] = -1;
        }
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); ++ i){
            for(int j = 0; j < i; ++ j){
                if(nums[i]%nums[j] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(maxsize < dp[i]){
                maxsize = dp[i];
                maxid = i;
            }
        }
        
        ans.resize(maxsize);
        int id = maxsize - 1;
        while(maxid != -1){
            ans[id --] = nums[maxid];
            maxid = prev[maxid];
        }
        
        return ans;
    }
};
