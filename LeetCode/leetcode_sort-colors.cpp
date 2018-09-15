/*
*
* Tag: Hash
* Tinme: O(n)
* Space: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colCnt[3] = {0};
        for(int num : nums)
            colCnt[num] ++;
        int idx = 0;
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < colCnt[i]; j ++){
                nums[idx] = i;
                ++ idx;
            }
        }
    }
};
