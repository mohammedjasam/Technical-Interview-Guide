/*
*
* Tag: Data Structure (HashMap)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        if(nums.size() == 0)
            return ans;
        unordered_map<int,int> dict;
        dict.clear();
        int sum = 0;
        for(int i = 0; i < nums.size(); ++ i){
            sum += nums[i];
            if(sum == k)
                ++ ans;
            if(dict.count(sum - k))
                ans += dict[sum - k];
            ++ dict[sum];
        }
        return ans;
    }
};
