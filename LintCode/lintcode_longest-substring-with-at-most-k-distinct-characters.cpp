/*
*
* Tag: Data Structure (Hash Map)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        int ans = 0;
        if(!s.size() || !k)
            return ans;
        unordered_map<char, int> dict;
        int cnt = 0, n = s.size(), len = 0, pre = 0;
        for(int i = 0; i < n; ++ i){
            char key = s[i];
            if(dict.find(key) == dict.end() || dict[key] == 0){
                dict[key] = 1;
                ++ len;
                ++ cnt;
            }else{
                ++ dict[key];
                ++ len;
            }
            if(cnt <= k)
                ans = max(ans, len);
            else{
                while(cnt > k && pre <= i){
                    char key = s[pre];
                    -- dict[key];
                    if(dict[key] == 0){
                        -- cnt;
                    }
                    -- len;
                    ++ pre;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
