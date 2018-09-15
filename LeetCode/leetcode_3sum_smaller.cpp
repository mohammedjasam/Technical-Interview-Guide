/*
*
* Tag: Two Pointers
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        if(nums.size() == 0) {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        int sta = 0, nd = nums.size() - 1;
        while(nd >= 2){
            sta = 0;
            int sum = nums[sta] + nums[nd];
            int sta_nd = nd - 1;
            while(sta < sta_nd){
                sum = nums[sta] + nums[nd];
                while(sum + nums[sta_nd] >= target && sta < sta_nd) 
                    -- sta_nd;
                ans += (sta_nd - sta);
                ++ sta;
            }
            -- nd;
        }
        
        return ans;
    }
};
