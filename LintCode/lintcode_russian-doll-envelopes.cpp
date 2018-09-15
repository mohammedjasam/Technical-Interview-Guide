/*
*
* Tag: DP
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() < 2)
            return envelopes.size();
        
        int res = 0, n = envelopes.size();
        vector<int> dp;
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if(it == dp.end())
                dp.push_back(envelopes[i].second);
            else
                *it = envelopes[i].second;
        }
        
        res = dp.size();
        return res;
    }

private:
    struct sortcmp {
	      bool operator() (pair<int, int> envelope_a, pair<int, int> envelope_b) { 
	          return envelope_a.first == envelope_b.first ? envelope_b.second < envelope_a.second : envelope_a.first < envelope_b.first;
	      }
	    } cmp;
};
