/*
*
* Tag: DP
* Time: O(n^3)
* Space: O(n^2)
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        bool dp[n][n];
        for(int i = n - 1; i >= 0; i --){
            for(int j = i; j < n; j ++){
                if(s[i] == s[j] && ((j - i) < 2 || (dp[i + 1][j - 1])))
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
        
        vector<vector<string> > ans[n];
        for(int i = n - 1; i >= 0; i --){
            for(int j = i; j < n; j ++){
                if(dp[i][j]){
                    const string palindrome = s.substr(i, j - i + 1);
                    if(j + 1 < n){
                        for(auto v : ans[j + 1]){
                            v.insert(v.begin(), palindrome);
                            ans[i].push_back(v);
                        }
                    }else{
                        ans[i].push_back(vector<string> {palindrome});
                    }
                }
            }
        }
        
        return ans[0];
    }
};
