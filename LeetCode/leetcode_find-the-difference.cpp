/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        if(t.size() <= s.size())
            return ans;
        vector<int> dict(26, 0);
        for(int i = 0; i < s.size(); ++ i){
            ++ dict[s[i] - 'a'];
        }
        for(int i = 0; i < t.size(); ++ i){
            -- dict[t[i] - 'a'];
            if(dict[t[i] - 'a'] < 0){
                ans = t[i];
                break;
            }
        }
        return ans;
    }
};

/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        if(t.size() <= s.size())
            return ans;
        for(int i = 0; i < s.size(); ++ i){
            ans ^= s[i];
        }
        for(int i = 0; i < t.size(); ++ i){
            ans ^= t[i];
        }
        return ans;
    }
};
