/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0)
            return ans;
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i] == -1 || nums[i] == i + 1)
                continue;
            while(nums[i] != i + 1 && nums[i] != -1){
                if(nums[i] == nums[nums[i] - 1]){
                    ans.push_back(nums[i]);
                    nums[i] = -1;
                }else
                    swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return ans;
    }
};
