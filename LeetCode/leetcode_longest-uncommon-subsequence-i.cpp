/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b?-1:max(a.size(), b.size());
    }
};
