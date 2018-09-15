/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int maxNums[3] = {INT_MIN, INT_MIN, INT_MIN}, minNums[3] = {INT_MAX, INT_MAX, INT_MAX};
        for(int i = 0; i < n; ++ i){
            if(nums[i] > maxNums[0]) {
                maxNums[2] = maxNums[1];
                maxNums[1] = maxNums[0];
                maxNums[0] = nums[i];
            } else if(nums[i] > maxNums[1]) {
                maxNums[2] = maxNums[1];
                maxNums[1] = nums[i];
            } else if(nums[i] > maxNums[2]) {
                maxNums[2] = nums[i];
            } 
            
            if(nums[i] < minNums[0]) {
                minNums[2] = minNums[1];
                minNums[1] = minNums[0];
                minNums[0] = nums[i];
            } else if(nums[i] < minNums[1]) {
                minNums[2] = minNums[1];
                minNums[1] = nums[i];
            }else if(nums[i] < minNums[2]) {
                minNums[2] = nums[i];
            }
        }
        
        return max(max(maxNums[0]*maxNums[1]*maxNums[2], maxNums[0]*minNums[0]*minNums[1]), minNums[0]*minNums[1]*minNums[2]);
    }
};
