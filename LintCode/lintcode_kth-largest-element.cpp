/*
*
* Tag: Sort
* Time: O(n)
* Space: O(1)
*
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int ans = 0;
        int n = nums.size(), pos = -1, start = 0, end = nums.size() - 1;
        while(pos != k){
            int pivot = nums[end];
            int tpos = start - 1;
            for(int i = start; i < end; ++ i){
                if(nums[i] < pivot){
                    swap(nums[i], nums[++tpos]);
                }
            }
            swap(nums[++ tpos], nums[end]);
            if(tpos == n - k){
                ans = nums[tpos];
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
