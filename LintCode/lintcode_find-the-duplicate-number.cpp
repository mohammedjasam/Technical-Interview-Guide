/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    const int DEFAULT_DUPLICATE_NUM = -1;
public:
    /*
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        int ans = DEFAULT_DUPLICATE_NUM;
        
        for(int i = 0; i < nums.size(); ++ i){
            int expected_value = i + 1;
            while(nums[i] != expected_value) {
                int expected_idx = nums[i] - 1;
                if(nums[i] == nums[expected_idx]){
                    ans = nums[i];
                    break;
                }
                swap(nums[i], nums[expected_idx]);
            }
            if(canStopSearchingDuplicateNumBasedOnAns(ans))
                break;
        }
        
        return ans;
    }
private:
    bool canStopSearchingDuplicateNumBasedOnAns(int ans) {
        return ans != DEFAULT_DUPLICATE_NUM;
    }
};
