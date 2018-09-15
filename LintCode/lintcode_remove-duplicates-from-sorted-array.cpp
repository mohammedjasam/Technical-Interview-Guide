/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if(!nums.size())
            return len;
        int id = 1, n = nums.size();
        for(int i = 1; i < n; ++ i){
            if(nums[i] != nums[i - 1]){
                nums[id ++] = nums[i];
            }else
                -- len;
        }
        return len;
    }
};
