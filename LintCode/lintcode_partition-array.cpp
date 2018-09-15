/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if(nums.size() == 0)
            return 0;
        int cnt = 0, n = nums.size();
        for(int i = 0; i < n; ++ i){
            if(nums[i] < k)
                ++ cnt;
        }
        if(!cnt)
            return cnt;
        int i = 0, j = n - 1;
        for(; i < cnt; ++ i){
            if(nums[i] >= k){
                while(nums[j] >= k)
                    -- j;
                swap(nums[i], nums[j]);
            }
        }
       return cnt;
    }
};
