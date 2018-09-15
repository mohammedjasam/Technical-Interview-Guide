/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; ++ i){
            ans[i] = nums[i];
        }
        for(int i = 1; i < n; ++ i){
            ans[i] = ans[i - 1]*nums[i];
        }
        for(int i = n - 2; i >= 0; -- i){
            nums[i] = nums[i]*nums[i + 1];
        }
        ans[n - 1] = ans[n - 2];
        int pre = ans[0], tmp = ans[0];
        for(int i = 1; i < n - 1; ++ i){
            pre = ans[i];
            ans[i] = tmp*nums[i + 1];
            tmp = pre;
        }
        ans[0] = nums[1];
        return ans;
    }
};
