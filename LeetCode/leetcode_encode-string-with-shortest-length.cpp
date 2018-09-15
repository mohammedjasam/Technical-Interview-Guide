/*
*
* Tag: DP
* Time: O(n^3)
* Space: O(n^2)
*/
class Solution {
private:
    string conpressStr(string &s, int i, int j, vector<vector<string>> &dp){
        string tmp = s.substr(i, j - i + 1);
        int idx = (tmp + tmp).find(tmp, 1);
        if(idx >= s.size()){
            return tmp;
        }
        return to_string(tmp.size()/idx) + '['+dp[i][i + idx - 1]+']';
    }
    
public:
    string encode(string s) {
        if(s.size() == 0)
            return s;
        int n = s.size(), j = 0;
        string left = "", right = "", conpress = "";
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for(int len = 1; len <= n; ++ len){
            for(int i = 0; i + len - 1 < n; ++ i){
                j = i + len - 1;
                dp[i][j] = s.substr(i, len);
                for(int k = i; k < j; ++ k){
                    left = dp[i][k], right = dp[k + 1][j];
                    if(left.size() + right.size() < dp[i][j].size()){
                        dp[i][j] = left + right;
                    }
                }
                conpress = conpressStr(s, i, j, dp);
                if(conpress.size() < dp[i][j].size()){
                    dp[i][j] = conpress;
                }
            }
        }
        return dp[0][n - 1];
    }
};
