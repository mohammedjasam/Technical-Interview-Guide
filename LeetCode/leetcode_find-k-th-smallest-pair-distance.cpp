/*
*
* Tag: Binary Search
* Time: O(nlgw + nlgn) w is the difference between largest number and smallest number in the array.
* Space: O(1)
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int l = 0, r = nums[nums.size() - 1] - nums[0];
        while(l < r){
            int mid = (r + l)>>1;
            int cnt = 0;
            for(int i = 0, j = 0; i < n; ++ i){
                while(j < n && nums[j] - nums[i] <= mid) {
                    ++ j;
                }
                
                cnt += j - i - 1;
            }
            
            if(cnt < k){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
};
