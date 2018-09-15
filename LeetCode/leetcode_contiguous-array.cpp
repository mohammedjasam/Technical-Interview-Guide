/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 0)
            return ans;
        unordered_map<int,int> dict;
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; ++ i){
            sum += nums[i] == 0?-1:1;
            if(sum == 0)
                ans = max(ans, i + 1);
            if(dict.find(sum) == dict.end())
                dict[sum] = i;
            else
                ans = max(ans, i - dict[sum]);
        }
        return ans;
    }
};
