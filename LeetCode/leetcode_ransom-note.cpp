/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(!ransomNote.size())
            return true;
        if(ransomNote.size() && !magazine.size())
            return false;
        vector<int> magazcnt(26, 0);
        for(int i = 0;  i < magazine.size(); ++ i)
            ++ magazcnt[magazine[i] - 'a'];
        for(int i = 0; i < ransomNote.size(); ++ i){
            -- magazcnt[ransomNote[i] - 'a'];
            if(magazcnt[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};
