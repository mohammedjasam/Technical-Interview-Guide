/*
*
* Tag: Binary Search Tree (Data Structure)
* Time: O(nlgk)
* Space: O(k)
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0){
            return false;
        }
        
        set<long long> windows;
        for(int i = 0; i < nums.size(); ++ i){
            if(i > k){
                windows.erase(nums[i - k - 1]);
            }
            
            auto it = windows.lower_bound((long long)nums[i] - t);
            if(it != windows.end() && *it - nums[i] <= t){
                return true;
            }
            
            windows.insert(nums[i]);
        }
        
        return false;
    }
};
