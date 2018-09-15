/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int ans = 0;
        if(!heights.size())
            return ans;
        int l = 0, r = heights.size() - 1;
        while(l < r){
            ans = max(ans, min(heights[l], heights[r])*(r - l));
            if(heights[l] <= heights[r])
                ++ l;
            else
                -- r;
        }
        return ans;
    }
};
