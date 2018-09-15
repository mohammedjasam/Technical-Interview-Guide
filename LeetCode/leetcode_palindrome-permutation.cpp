/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.size() == 0){
            return true;
        }
        
        unordered_map<char,int> dict_cnt;
        for(int i = 0; i < s.size(); ++ i){
            if(dict_cnt.find(s[i]) == dict_cnt.end()) {
                dict_cnt[s[i]] = 1;
            } else {
                ++ dict_cnt[s[i]];
            }
        }
        
        int odd_cnt = 0;
        unordered_map<char,int>::iterator it = dict_cnt.begin();
        for(; it != dict_cnt.end(); ++ it){
            if((it->second)%2 == 1) {
                ++ odd_cnt;
            }
        }
        
        return odd_cnt <= 1 || dict_cnt.size() == 1;
    }
};
