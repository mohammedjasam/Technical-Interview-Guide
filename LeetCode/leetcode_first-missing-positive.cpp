/*
*
* Tag: Sort
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size())
            return 1;
            
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            while(nums[i] != i + 1){
                if(nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1])
                    break;
                
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        

        for(int i = 0; i < n; ++ i){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        
        return n + 1;
    }
};
