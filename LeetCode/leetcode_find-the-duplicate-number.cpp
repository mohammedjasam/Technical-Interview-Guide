/*
*
* Tag: Sort
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < nums.size(); ++ i) {
            while(nums[i] != i + 1) {
                if(nums[i] == nums[nums[i] - 1]) {
                    ans = nums[i];
                    break;
                }
                
                swap(nums[i], nums[nums[i] - 1]);
            }
            
            if(ans != 0) {
                break;
            }
        }
        
        return ans;
    }
};
