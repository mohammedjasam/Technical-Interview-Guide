/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int ans = 0;
        if(!height.size())
            return ans;
        stack<int> stk;
        height.push_back(0);
        for(int i = 0; i < height.size(); ){
            if(stk.empty() || height[i] > height[stk.top()])
                stk.push(i ++);
            else{
                int id = stk.top();
                stk.pop();
                ans = max(ans, height[id]*(stk.empty()?i:i-stk.top()-1));
            }
        }
        return ans;
    }
};
