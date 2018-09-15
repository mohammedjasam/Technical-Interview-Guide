/*
* Tag: Bit Manipulation
* Time : O(n)
* Memory : O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitCount(32, 0);
        if(nums.size() == 1){
            return nums[0];
        }
        
        for(int num : nums){
            for(int i = 0; i < 32; ++ i){
                bitCount[i] = (bitCount[i] + ((num>>i)&1))%3;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < bitCount.size(); ++ i){
            ans |= (bitCount[i]<<i);
        }
        
        return ans;
    }
};
