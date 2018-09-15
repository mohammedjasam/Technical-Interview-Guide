/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        if(heights.size() == 0){
            return ans;
        }
        
        stack<int> stk;
        heights.push_back(0);
        for(int i = 0; i < heights.size();) {
            if(stk.empty() || heights[stk.top()] < heights[i]) {
                stk.push(i ++);
            } else {
                int idx = stk.top();
                stk.pop();
                ans = max(ans, heights[idx]*(stk.empty() ? i : (i - stk.top() - 1)));
            }
        }
        
        return ans;
    }
};
