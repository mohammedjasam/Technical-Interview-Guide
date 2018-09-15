/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(nRows <= 1) return s;
        string ret;
        int zigsize = 2 * nRows - 2;
        for(int i = 0; i < nRows; ++i) {
            for(int base = i; ;base += zigsize) {
                if(base >= s.size())
                    break;
                ret.append(1,s[base]);
                if(i > 0 && i < nRows - 1) {
                    //middle need add ziggggging char
                    int ti = base + zigsize - 2 * i;
                    if(ti < s.size())
                        ret.append(1,s[ti]);
                }
            }
        }
        return ret;
    }
};
