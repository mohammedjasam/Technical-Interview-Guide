/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        int cnt = nums.size()/k, ans;
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

