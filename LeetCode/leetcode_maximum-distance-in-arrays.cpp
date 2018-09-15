/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int lmax = INT_MIN, ans = INT_MIN, n = arrays.size();
        vector<int> rmax(n, INT_MIN);
        for(int i = n - 1; i > 0; -- i){
            int m = arrays[i].size();
            if(i == n - 1)
                rmax[i] = arrays[i][m - 1];
            else
                rmax[i] = max(arrays[i][m - 1], rmax[i + 1]);
        }
        for(int i = 0; i < n; ++ i){
            int m = arrays[i].size();
            if(i == 0)
                ans = max(ans, abs(rmax[1] - arrays[0][0]));
            else if(i == n - 1)
                ans = max(ans, abs(lmax - arrays[n - 1][0]));
            else
                ans = max(ans, abs(max(lmax, rmax[i + 1]) - arrays[i][0]));
            lmax = max(lmax, arrays[i][m - 1]);
        }
        return ans;
    }
};
