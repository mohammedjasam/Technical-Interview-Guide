/*
*
* Tag: Greedy
* Time: O(ngln)
* Space: O(lgn)
*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        if(nums.size() == 0)
            return sum;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }
};
