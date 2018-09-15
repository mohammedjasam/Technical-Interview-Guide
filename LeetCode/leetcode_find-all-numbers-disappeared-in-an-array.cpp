/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0){
            return ans;
        }
        
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i] == i + 1 || nums[i] == -1){
                continue;
            }
            
            while(nums[i] != i + 1 && nums[i] != -1){
                if(nums[i] == nums[nums[i] - 1]){
                    nums[i] = -1;
                    ++ cnt;
                } else {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
        
        ans.resize(cnt);
        for(int i = 0, j = 0; i < nums.size() && j < cnt; ++ i){
            if(nums[i] == -1){
                ans[j ++] = i + 1;
            }
        }
        return ans;
    }
};
