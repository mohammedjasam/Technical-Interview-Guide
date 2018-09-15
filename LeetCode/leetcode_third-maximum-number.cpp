/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        vector<long long> max_val(3, LLONG_MIN);
        for(int i = 0; i < n; ++ i){
            if(nums[i] == max_val[0] || nums[i] == max_val[1] || nums[i] == max_val[2])
                continue;
            if(nums[i] > max_val[0]){
                max_val[2] = max_val[1];
                max_val[1] = max_val[0];
                max_val[0] = nums[i];
            }else if(nums[i] > max_val[1]){
                max_val[2] = max_val[1];
                max_val[1] = nums[i];
            }else if(nums[i] > max_val[2]){
                max_val[2] = nums[i];
            }
        }
        return max_val[2] != LLONG_MIN? (int)max_val[2] : (int)max_val[0];
    }
};
