/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(lgn)
*/
class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if(!nums.size())
            return ;
        int idx = 0, minval = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            if(minval > nums[i]){
                minval = nums[i];
                idx = i;
            }
        }
        if(!idx)
            return ;
        int lenl = idx, lenr = n - idx;
        recover(nums, n, idx, lenl, lenr);
    }
    
    void recover(vector<int> &nums, int n, int start, int lenl, int lenr){
        for(int i = start - lenl, j = start; i < start && j < n; ++ i, ++ j)
                swap(nums[i], nums[j]);
        if(lenl == lenr){
            return ;
        }else if(lenl < lenr){
            start += lenl;
            lenr -= lenl;
            recover(nums, n, start, lenl, lenr);
            return ;
        }else{
            lenl -= lenr;
            recover(nums, n, start, lenl, lenr);
            return ;
        }
    }
};
