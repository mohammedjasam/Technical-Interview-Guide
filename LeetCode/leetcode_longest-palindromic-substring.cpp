/*
*
* Tag: DP
* Time: O(n^2) (can be reduced to O(n))
* Space: O(n^2)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.size();
        if(n == 0){
            return s;
        }
        
        bool dp[n][n];
        int maxlen = 0, startIndex = 0;
        for(int i = n - 1; i >= 0; i --){
            for(int j = i; j < n; j ++){
                if(s[i] == s[j] && ((j - i < 2) || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
                
                if(dp[i][j] && j - i + 1 > maxlen){
                    maxlen = j - i + 1;
                    startIndex = i;
                }
            }
        }
        ans = s.substr(startIndex, maxlen);
        
        return ans;
    }
};
