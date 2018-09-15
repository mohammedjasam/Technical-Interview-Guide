/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int ans = INT_MIN, minVal = 1, maxVal = 1;
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i] == 0) {
                ans = max(0, ans);
                continue;
            }else if(i == 0 || nums[i - 1] == 0) {
                minVal = maxVal = nums[i];
            } else {
                int tmpMaxVal = maxVal;
                maxVal = max(nums[i], max(maxVal*nums[i], minVal*nums[i]));
                minVal = min(nums[i], min(tmpMaxVal*nums[i], minVal*nums[i]));
            }
            
            ans = max(ans, maxVal);
        }
        
        return ans;
    }
};
