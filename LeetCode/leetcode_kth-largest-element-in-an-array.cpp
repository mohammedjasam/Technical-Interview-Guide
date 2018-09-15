/*
*
* Tag: Order Statistics
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans = 0;
        int start = 0, end = nums.size() - 1, n = nums.size(), tpos = 0, pivot = 0;
        while(1){
            pivot = nums[end], tpos = start - 1;
            for(int i = start; i < end; ++ i){
                if(nums[i] < pivot)
                    swap(nums[++ tpos], nums[i]);
            }
            swap(nums[++ tpos], nums[end]);
            if(tpos == n - k){
                ans = nums[n - k];
                break;
            }else if(tpos > n - k){
                end = tpos - 1;
            }else{
                start = tpos + 1;
            }
        }
        return ans;
    }
};
