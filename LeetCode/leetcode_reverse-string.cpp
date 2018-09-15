/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string reverseString(string s) {
        if(!s.size())
            return s;
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i], s[j]);
            ++ i;
            -- j;
        }
        return s;
    }
};
