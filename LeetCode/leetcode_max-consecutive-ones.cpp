/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 0)
            return ans;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++ i){
            sum = (sum + nums[i])*nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
