/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        string ans = "";
        if(!s.size())
            return ans;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int maxlen = 0;
        for(int i = n - 1; i >= 0; -- i){
            for(int j = i; j < n; ++ j){
                if(s[i] == s[j] && (j-i<2 || (dp[i + 1][j - 1])))
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
                if(dp[i][j] && maxlen < j - i + 1){
                    maxlen = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};
