/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, len = 0;
        if(!s.size()) {
            return ans;
        }
        
        vector<bool> vis(300, false);
        for(int i = 0, j = 0; j < s.size(); ){
            if(!vis[(int)s[j]]){
                vis[(int)s[j] ] = 1;
                ++ j;
                ++ len;
            }else{
                vis[(int)s[i]] = 0;
                -- len;
                ++ i;
            }
            ans = max(ans, len);
        }
        
        return ans;
    }
};
