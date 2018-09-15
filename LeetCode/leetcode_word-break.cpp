/*
*
* Tag: DP
* Time: O(n^3)
* Space: O(n)
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(wordDict.find(s) != wordDict.end())
            return true;
        if(wordDict.size() == 0)
            return false;
        vector<bool> dp(s.size() + 1, false);
        string word;
        dp[0] = 1;
        for(int i = 1; i <= s.size(); ++ i){
            for(int j = i - 1; j >= 0; -- j){
                if(dp[j]){
                    word = s.substr(j, i - j);
                    if(wordDict.find(word) != wordDict.end()){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
