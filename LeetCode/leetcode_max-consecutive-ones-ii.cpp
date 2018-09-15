/*
*
* Tag: Pointer
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt[2] = {0};
        if(nums.size() == 0)
            return ans;
        int i = 0;
        while(i < nums.size() && nums[i] == 0) ++ i;
        if(i >= nums.size()){
            return (ans=1);
        }
        if(i == 0)
            cnt[0] = -1;
        for(; i <= nums.size(); ++ i){
            if(i == nums.size() || nums[i] == 0){
                ans = max(ans, cnt[0] + cnt[1] + 1);
                cnt[0] = cnt[1];
                cnt[1] = 0;
            }else
                ++ cnt[1];
        }
        return ans;
    }
};
