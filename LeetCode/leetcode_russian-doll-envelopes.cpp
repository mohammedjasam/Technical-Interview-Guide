/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int ans = 0;
        vector<int> dp;
        if(!envelopes.size())
            return ans;
        sort(envelopes.begin(), envelopes.end(), cmpfunc);
        dp.resize(envelopes.size());
        dp[0] = 1;
        ans = 1;
        for(int i = 1; i < envelopes.size(); ++ i){
            dp[i] = 0;
            for(int j = 0; j < i; ++ j){
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
                    dp[i] = max(dp[i], dp[j]);
            }
            ++ dp[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
private:
    struct cmp{
	   bool operator() (const pair<int, int> &a, const pair<int, int> &b){
	        return a.first*a.second < b.first*b.second; 
	   }
	}cmpfunc;
};
