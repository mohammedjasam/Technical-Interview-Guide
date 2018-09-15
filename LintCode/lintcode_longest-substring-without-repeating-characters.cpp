/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int ans = 0;
        if(!s.size())
            return ans;
        vector<bool> haschar(256);
        int l = 0, n = s.size(), len = 0;
        for(int r = 0; r < n; ++ r){
            int idx = (int)s[r];
            if(!haschar[idx]){
                ++ len;
                haschar[idx] = 1;
                ans = max(ans, len);
            }else{
                int targ_idx = idx;
                idx = (int)s[l];
                haschar[targ_idx] = 1;
                while(targ_idx != idx && l < r){
                    haschar[idx] = false;
                    -- len;
                    ++ l;
                    idx = (int)s[l];
                }
                ++ l;
            }
        }
        return ans;
    }
};
