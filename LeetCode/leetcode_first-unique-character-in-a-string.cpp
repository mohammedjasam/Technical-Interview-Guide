/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int firstUniqChar(string s) {
        if(!s.size())
            return -1;
        vector<int> dict(26, -1);
        for(int i = 0; i < s.size(); ++ i){
            if(dict[s[i] - 'a'] == -1)
                dict[s[i] - 'a'] = i;
            else if(dict[s[i] - 'a'] >= 0)
                dict[s[i] - 'a'] = -2;
        }
        int ans = INT_MAX;
        for(int i = 0; i < 26; ++ i){
            if(dict[i] >= 0)
                ans = min(ans, dict[i]);
        }
        return ans == INT_MAX?-1:ans;
    }
};
