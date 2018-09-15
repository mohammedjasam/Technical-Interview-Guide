/*
*
* Tag: Brute Force (Two Pointers)
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int p1 = nums[0], p2 = INT_MAX;
        for(int i = 1; i < nums.size(); ++ i){
            if(nums[i] < p1){
                p1 = nums[i];
            }else if(nums[i] > p2){
                return true;
            }else if(nums[i] > p1 && nums[i] < p2){
                p2 = nums[i];
            }
        }
        return false;
    }
};
