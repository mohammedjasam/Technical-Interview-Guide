/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/

// O(n)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        if(s.size() == 0) {
            return ans;
        }
        
        int n = s.size();
        if(n < 3) {
            return n;
        }
        
        vector<int> recd(300, 0);
        ++ recd[s[0] - 'A'];
        
        int head = 0, tail  = 1, cnt = 0;
        ++ cnt;
        for(; tail < n; ++ tail){
            if(recd[s[tail] - 'A'] == 0)
                cnt ++;
            ++ recd[s[tail] - 'A'];
            if(cnt <= 2)
                ans = max(ans, tail + 1 - head);
            else{
                while(cnt > 2 && head < tail){
                    -- recd[s[head] - 'A'];
                    if(recd[s[head] - 'A'] == 0)
                        cnt --;
                    head ++;
                }
                ans = max(ans, tail + 1 - head);
            }
        }
        
        return ans;
    }
};
