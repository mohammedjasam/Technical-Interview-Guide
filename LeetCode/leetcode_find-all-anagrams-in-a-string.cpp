/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()) {
            return ans;
        }
        
        vector<int> pcnt(26, 0), scnt(26, 0);
        for(int i = 0; i < p.size(); ++ i){
            ++ pcnt[p[i]-'a'];
            ++ scnt[s[i] - 'a'];
        }
        
        if(pcnt == scnt) {
            ans.push_back(0);
        }
        for(int i = p.size(); i < s.size(); ++ i){
            ++ scnt[s[i] - 'a'];
            -- scnt[s[i - p.size()] - 'a'];
            if(pcnt == scnt) {
                ans.push_back(i - p.size() + 1);
            }
        }
        
        return ans;
    }

};
