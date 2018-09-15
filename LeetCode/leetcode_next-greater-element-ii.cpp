/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0)
            return ans;
        vector<int> stk(2*nums.size());
        ans.resize(nums.size());
        int top = 0;
        for(int i = 2*nums.size() - 1; i >= 0; -- i){
            while(top > 0 && nums[(i%nums.size())] >= stk[top - 1])
                -- top;
            if(top == 0)
                ans[(i%nums.size())] = -1;
            else
                ans[(i%nums.size())] = stk[top - 1];
            stk[top ++] = nums[(i%nums.size())];
        }
        return ans;
    }
};
