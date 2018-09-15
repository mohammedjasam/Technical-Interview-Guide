/*
*
* Tag: Memory Search (Hash Search)
* Time: O(n)
* Space: O(1)
*
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        search(nums);
        int ans = -1, n = nums.size();
        for(int i = 0; i < n; ++ i){
            if(nums[i] != i){
                ans = i;
                break;
            }
        }
        return ans==-1?n:ans;
    }
    
private:
    void search(vector<int> &nums){
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            if(nums[i] >= 0 && nums[i] < n){
                while(nums[i] != i){
                    swap(nums[i], nums[nums[i]]);
                    if(nums[i] < 0 || nums[i] >= n)
                        break;
                }
            }
        }
    }
};
