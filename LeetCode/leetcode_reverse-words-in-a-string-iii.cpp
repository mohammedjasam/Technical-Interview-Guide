/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0)
            return s;
        int i = 0, j = 0;
        for(int j = 0; j < s.size(); ++ j){
            if(j == s.size() - 1 || s[j] == ' '){
                if(j == s.size() - 1)
                    ++ j;
                reverseStr(i, j - 1, s);
                i = j + 1;
            }
        }
        return s;
    }
private:
    void reverseStr(int sta, int end, string &s){
        int i = sta, j = end;
        while(i < j){
            swap(s[i], s[j]);
            ++i, -- j;
        }
    }
};
