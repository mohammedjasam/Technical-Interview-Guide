/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string s) {
        // Write your code here
        int ans = 0;
        if(!s.size())
            return ans;
        int n = s.size();
        vector<int> dp(3);
        dp[0] = 1;
        dp[1] = s[0] != '0'?1:0;
        dp[2] = 0;
        for(int i = 1; i < n; ++ i){
            if(s[i] != '0'){
                dp[2] = dp[1];
            }
            if(i){
                if((s[i] <= '6' && s[i - 1] == '2') 
                    || (s[i - 1] == '1')){
                    dp[2] += dp[0];
                }
            }
            
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = 0;
        }
        return dp[1];
    }
};
