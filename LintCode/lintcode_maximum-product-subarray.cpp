/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int ans = INT_MIN;
        if(nums.size() == 0)
            return 0;
        long long mul = 1;
        int n = nums.size(), l = 0;
        for(int i = 0; i < n; ++ i){
            if(nums[i] == 0){
                ans = max(ans, nums[i]);
                while(l < i - 1){
                    mul/=nums[l];
                    ++ l;
                    ans = max((long long)ans, mul);
                }
                l = i + 1;
                mul = 1;
            }else{
                mul *= nums[i];
                ans = max((long long)ans, mul);
            }
        }
        
        for(; l < n - 1; ++ l){
            mul /= nums[l];
            ans = max(mul, (long long)ans);
        }
        return ans;
    }
};
