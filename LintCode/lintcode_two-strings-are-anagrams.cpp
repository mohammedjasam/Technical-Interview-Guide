/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if(s=="" && t=="")
            return true;
        if(s.size() != t.size())
            return false;
        vector<int> s_recd(26), t_recd(26);
        for(int i = 0; i < s.size(); ++ i){
            if(s[i] >= 'a' && s[i] <= 'z')
                ++ s_recd[s[i] - 'a'];
        }
        for(int i = 0; i < s.size(); ++ i){
            if(t[i] >= 'a' && t[i] <= 'z')
                ++ t_recd[t[i] - 'a'];
        }
        for(int i = 0; i < 26; ++ i)
            if(s_recd[i] != t_recd[i])
                return false;
        return true;
    }
};
