/*
*
* Tag: Merge Sort
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
private:
    int ans;
public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        if(nums.size() == 0)
            return ans;
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
private:
    void mergeSort(vector<int>& nums, int start, int end){
        if(start == end)
            return ;
        int mid = (start + end)>>1;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        
        mergeCnt(nums, start, mid, end);
        return ;
    }
    
    void mergeCnt(vector<int>& nums, int start, int mid, int end){
        int l = start, r = mid + 1, idx = 0;
        while(l <= mid && r <= end){
            if((long long)nums[l] > (long long)2*nums[r]){
                ans += (mid - l + 1);
                ++ r;
            }else{
                ++ l;
            }
        }
        
        vector<int> tmp(end - start + 1);
        l = start, r = mid + 1;
        while(l <= mid && r <= end){
            if(nums[l] <= nums[r])
                tmp[idx] = nums[l ++];
            else
                tmp[idx] = nums[r ++];
            ++ idx;
        }
        while(l <= mid){
            tmp[idx] = nums[l ++];
            ++ idx;
        }
        while(r <= end){
            tmp[idx] = nums[r ++];
            ++ idx;
        }
        for(int i = start, j = 0; i <= end; ++ i, ++ j)
            nums[i] = tmp[j];
    }
    
};
