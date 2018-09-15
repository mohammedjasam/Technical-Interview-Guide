/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(!nums.size())
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++ i){
            if(nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};
