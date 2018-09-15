/*
*
* Tag: Brute Force (Or Greedy)
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, n = s.size(), right_char_cnt = 0, fidx = 0, bidx = 0;
        if(!s.size() || k <= 1)
            return n;
        vector<int> cnt(26, 0), totcnt(26, 0), tmpcnt(26, 0);
        for(int i = 0; i < n; ++ i)
            ++ totcnt[s[i] - 'a'];
        for(int i = 0; i < n; ++ i){
            if(totcnt[s[i] - 'a'] < k){
                for(int j = 0; j < 26; ++ j)
                    totcnt[j] -= cnt[j];
                bidx = i - 1;
                while(cnt[s[fidx] - 'a'] < k && fidx < i){
                    -- cnt[s[fidx] - 'a'];
                    ++ fidx;
                }
                while(cnt[s[bidx] - 'a'] < k && fidx < bidx){
                    -- cnt[s[bidx] - 'a'];
                    -- bidx;
                }
                
                if(fidx < bidx && check(cnt, k))
                    res = max(res, bidx - fidx + 1);
                for(int j = 0; j < 26; ++ j)
                    cnt[j] = 0;
                fidx = i + 1;
                right_char_cnt = 0;
                
            }else{
                ++ cnt[s[i] - 'a'];
                if(cnt[s[i] - 'a'] == k)
                    -- right_char_cnt;
                else if(cnt[s[i] - 'a'] == 1)
                    ++ right_char_cnt;
                if(!right_char_cnt)
                    res = max(res, i + 1 - fidx);
            }
        }
        return res;
    }
    
private:
    bool check(vector<int> &cnt, int k){
        for(int i = 0; i < cnt.size(); ++ i){
            if(cnt[i] && cnt[i] < k)
                return false;
        }
        return true;
    }
};
