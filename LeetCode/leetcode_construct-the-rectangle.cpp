/*
*
* Tag: Math
* Time: O(sqrt(n))
* Space: O(1)
*/
class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2);
        int w = (int)sqrt(area);
        while(w >= 1){
            if(area%w == 0){
                ans[0] = area/w, ans[1] = w;
                break;
            }
            -- w;
        }
        return ans;
    }
};
