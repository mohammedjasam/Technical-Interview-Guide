/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if(!nums.size())
            return ;
        int n = nums.size(), odd_cnt = 0, even_cnt = 0;
        for(int i = 0; i < n; ++ i){
            if(nums[i]%2)
                ++ odd_cnt;
            else
                ++ even_cnt;
        }
        int bnd = odd_cnt;
        int odd_idx = 0, even_idx = n - 1;
        while(odd_idx < bnd && even_idx >= bnd){
            if(nums[odd_idx]%2 == 0){
                while(nums[even_idx]%2 == 0 && even_idx >= bnd){
                    -- even_idx;
                }
                if(even_idx >= bnd)
                    swap(nums[even_idx], nums[odd_idx]);
            }else{
                ++ odd_idx;
            }
        }
        return ;
    }
};
