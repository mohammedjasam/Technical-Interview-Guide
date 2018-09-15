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
        if(!nums.size())
            return 0;
        int n = nums.size();
        int cur = 1, cnt = 1;
        for(int i = 1; i < n; ++ i){
            if(nums[i] == nums[i - 1]){
                ++ cnt;
                if(cnt <= 2){
                    nums[cur ++] = nums[i];
                }
            }else{
                cnt = 1;
                nums[cur ++] = nums[i];
            }
        }
        return cur;
    }
};
