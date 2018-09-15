/*
*
* Tag: Sort
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = (nums.size() + 1)/2;
        int v = orderStatistics(nums, mid - 1), res = 0;
        for(int i = 0; i < nums.size(); ++ i)
            res += abs(nums[i] - v);
        return res;
    }
private:
    int orderStatistics(vector<int>&nums, int k){
        int res = 0, tpos = 0, start = 0, end = nums.size() - 1, pivote = 0, n = nums.size() - 1;
        while(1){
            tpos = start - 1, pivote = nums[end];
            for(int i = start; i < end; ++ i){
                if(nums[i] < pivote)
                    swap(nums[++ tpos], nums[i]);
            }
            swap(nums[end], nums[++ tpos]);
            if(tpos == n - k){
                res = nums[tpos];
                break;
            }else if(tpos < n - k){
                start = tpos + 1;
            }else{
                end = tpos - 1;
            }
        }
        return res;
    }
};
