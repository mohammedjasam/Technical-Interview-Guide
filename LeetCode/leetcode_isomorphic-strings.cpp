/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s_mp[300] = {0}, t_mp[300] = {0};
        for(int i = 0; i < s.size(); ++ i){
            s_mp[s[i]] = t[i];
            t_mp[t[i]] = s[i];
        }
        for(int i = 0; i < s.size(); ++ i){
            if(s_mp[s[i]] != t[i] || t_mp[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
