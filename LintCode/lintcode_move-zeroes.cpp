/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int cntzeros = 0;
        if(!nums.size())
            return ;
        int id = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i])
                nums[id ++] = nums[i];
            else
                ++ cntzeros;
        }
        while(cntzeros --)
            nums[id ++] = 0;
    }
};
