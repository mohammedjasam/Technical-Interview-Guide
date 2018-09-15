/*
*
* TODO
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0,  r = height.size() - 1;
        int ans = INT_MIN;
        while(l < r){
            ans = max(ans, min(height[l],height[r])*(r - l));
            if(height[l] <= height[r]){
                l ++;
            }else{
                r --;
            }
        }
        
        return ans;
    }
};
