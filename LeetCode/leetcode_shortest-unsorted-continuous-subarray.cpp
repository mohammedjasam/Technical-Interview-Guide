/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmparr(nums);
        sort(tmparr.begin(), tmparr.end());
        int lbnd = 0, rbnd = nums.size() - 1;
        for(; lbnd < nums.size() && tmparr[lbnd] == nums[lbnd]; ++ lbnd) ;
        if(lbnd >= nums.size())
            return 0;
        for(; rbnd >= 0 && tmparr[rbnd] == nums[rbnd]; -- rbnd) ;
        return rbnd - lbnd + 1;
    }
};
