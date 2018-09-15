/*
*
* Tag: Sort
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        if(!nums.size())
            return 0;
        int k = nums.size()/2;
    //    if(nums.size()%2)
        ++ k;
        return getKth(nums, k);
    }
    
    int getKth(vector<int> nums, int k){
        int start = 0, end = nums.size() - 1;
        int n = nums.size();
        int ans;
        while(start <= end){
            int tpos = start - 1;
            int pivot = nums[end];
            for(int i = start; i < end; ++ i){
                if(nums[i] < pivot)
                    swap(nums[i], nums[++ tpos]);
            }
            swap(nums[end], nums[++ tpos]);
            if(tpos == n - k){
                ans = nums[tpos];
                break;
            }else if(tpos < n - k){
                start = tpos + 1;
            }else
                end = tpos - 1;
        }
        return ans;
    }
};

