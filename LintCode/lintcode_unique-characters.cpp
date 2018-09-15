/*
*
* Tag: Sort or Hash
* Time: O(nlgn) or O(n)
* Space: O(lgn) or O(n)
*/
class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        string tmp_str = str;
        sort(tmp_str.begin(), tmp_str.end());
        int len = tmp_str.size() - 1;
        for(int i = 0; i < len; ++ i)
            if(tmp_str[i] == tmp_str[i + 1])
                return false;
        return true;
    }
};
