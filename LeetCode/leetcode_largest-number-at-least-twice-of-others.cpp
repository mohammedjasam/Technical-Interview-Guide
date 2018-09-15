/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        
        int maxNum = INT_MIN, secondMaxNum = INT_MIN;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i] > maxNum){
                secondMaxNum = maxNum;
                maxNum = nums[i];
                ans = i;
            } else if(nums[i] > secondMaxNum) {
                secondMaxNum = max(secondMaxNum, nums[i]);
            }
        }
        
        return (secondMaxNum<<1) <= maxNum ? ans : -1;
    }
};
