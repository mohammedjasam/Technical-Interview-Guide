/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = "";
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            if(i >= 1)
                ans += "/";
            if(i == 1 && n >= 3)
                ans += "(";
            ans += to_string(nums[i]);
            if(i == n - 1 && n >= 3)
                ans += ")";
        }
        return ans;
    }
};
