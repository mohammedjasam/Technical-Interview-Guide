/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int cnt = nums.size()/3, ans;
        unordered_map<int,int> dict;
        for(int i = 0; i < nums.size(); ++ i){
            if(dict.find(nums[i]) == dict.end())
                dict[nums[i]] = 1;
            else
                ++ dict[nums[i]];
            if(dict[nums[i]] > cnt){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};

