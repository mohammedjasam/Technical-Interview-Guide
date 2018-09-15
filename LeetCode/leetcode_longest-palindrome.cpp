/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        if(s.size() == 0)
            return ans;
        int cnt[60], odd_cnt = 0, uniq = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < s.size(); ++ i){
            if(s[i] >= 'a' && s[i] <= 'z')
                ++ cnt[(int)(s[i] - 'a')];
            else if(s[i] >= 'A' && s[i] <= 'Z')
                ++ cnt[(int)(s[i] - 'A')+26];
        }
        for(int i = 0; i < 60; ++ i){
            if(cnt[i]%2 == 0)
                ans += cnt[i];
            else{
                ans += (cnt[i] - 1);
                ++ odd_cnt;
            }
            if(cnt[i])
                ++ uniq;
        }
        
        return uniq == 1?s.size():odd_cnt?ans+1:ans;
    }
};
