/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 1, n = nums.size();
        for(int i = 0; i < reach && reach < n; i ++){
            reach = max(reach, nums[i] + i + 1);
        }
        
        return reach >= n;
    }
};
