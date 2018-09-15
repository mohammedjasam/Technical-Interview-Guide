/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int ans = 0;
        if(p.size() == 0)
            return ans;
        vector<int> cnt(26, 0);
        int cur = 0, len = 0;
        for(int i = 0; i < p.size(); ++ i){
            cur = p[i] - 'a';
            if(i > 0 && p[i - 1] != (cur + 25)%26 + 'a') len = 0;
            if(++ len > cnt[cur]){
                ans += len - cnt[cur];
                cnt[cur] = len;
            }
        }
        return ans;
    }
};
