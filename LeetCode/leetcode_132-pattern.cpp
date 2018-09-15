/*
*
* Tag: Data Structure (stack)
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s2 = INT_MIN;
        stack<int> stk;
        for(int i = nums.size() - 1; i >= 0; -- i){
            if(nums[i] < s2)
                return true;
            else while(!stk.empty() && stk.top() < nums[i]){
                s2 = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
