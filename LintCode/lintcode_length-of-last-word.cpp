/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int ans = 0;
        if(!s.size())
            return ans;
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' ')
            -- i;
        if(!i)
            return ans;
        while(i >= 0 && s[i] != ' '){
            -- i;
            ++ ans;
        }
        return ans;
    }
};
