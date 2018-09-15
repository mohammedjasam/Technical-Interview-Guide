/*
* 
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        if(findNums.size() == 0 || nums.size() == 0)
            return ans;
        unordered_map<int,int> tmpans;
        vector<int> stk(nums.size());
        int top = 0;
        for(int i = nums.size() - 1; i >= 0; -- i){
            while(top > 0 && nums[i] > stk[top - 1])
                -- top;
            if(top == 0)
                tmpans[nums[i]] = -1;
            else
                tmpans[nums[i]] = stk[top - 1];
            stk[top ++] = nums[i];
        }
        ans.resize(findNums.size());
        for(int i = 0; i < findNums.size(); ++ i){
            ans[i] = tmpans[findNums[i]];
        }
        return ans;
    }
};
