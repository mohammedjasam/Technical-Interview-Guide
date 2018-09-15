/*
*
* Tag: DP
* Time: O(n*2^n)
* Space: O(2^n)
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        if(s.size() == 0 || wordDict.size() == 0){
            return ans;
        }
        
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dpForCheck(n + 1, false);
        dpForCheck[0] = true;
        for(int i = 1; i <= n; ++ i){
            for(int j = i - 1; j >= 0; -- j){
                if(dpForCheck[j]) {
                    string word = s.substr(j, i - j);
                    if(dict.count(word) != 0){
                        dpForCheck[i] = true;
                        break;
                    }
                }
            }
        }
        
        if(!dpForCheck[n]) {
            return ans;
        }
        
        vector<vector<string>> dp(n + 1, vector<string>());
        dp[0].push_back("");
        for(int i = 1; i <= n; ++ i){
            for(int j = i - 1; j >= 0; -- j){
                if(dp[j].size() == 0) {
                    continue;
                }
                
                string word = s.substr(j, i - j);
                if(dict.count(word) == 0){
                    continue;
                }
                
                for(string prev : dp[j]) {
                    dp[i].push_back(prev == "" ? word : prev + " " + word);
                }
            }
        }
        
        return dp[n];
    }
};
