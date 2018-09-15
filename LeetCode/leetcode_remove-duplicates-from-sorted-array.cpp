/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        
        int len = n, i = 0, j = 1;
        for(; j < n; j ++){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
                len --;
            }
        }
        i ++;
        
        return i;
    }
};
