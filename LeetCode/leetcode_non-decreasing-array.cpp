/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 0)
            return true;
        int numOfReverse = 0, numOfElementsOfFirstNonDecreasingArray = 0, indexOfFirstReverseNumber = 0;
        for(int i = 0; i < nums.size() - 1; ++ i){
            if(nums[i] > nums[i + 1]) {
                ++ numOfReverse;
                if(i == 0 || nums[i - 1] <= nums[i + 1]){
                    nums[i] = nums[i + 1];
                } else {
                    nums[i + 1] = nums[i];
                }
            }
        }
        return numOfReverse <= 1;
    }
};
