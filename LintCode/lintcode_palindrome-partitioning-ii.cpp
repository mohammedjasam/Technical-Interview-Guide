/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int n = s.size();
        vector<int> ans(n);
        bool palid[n][n];
        for(int i = n - 1; i >= 0; i --){
            for(int j = i; j < n; j ++){
                if(s[i] == s[j] && ((j - i < 2) || palid[i + 1][j - 1]))
                    palid[i][j] = true;
                else
                    palid[i][j] = false;
            }
        }
        for(int i = 0; i < n; i ++)
            ans[i] = INT_MAX;
        for(int i = 0; i < n; i ++){
            if(palid[0][i])
                ans[i] = 0;
        }
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++){
                if(ans[j] != INT_MAX && palid[j + 1][i]){
                    ans[i] = min(ans[j] + 1, ans[i]);
                }
            }
        }
        return ans[n - 1];
    }
};
