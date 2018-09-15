/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n == 0? false : log10(n)/log10(3) == floor(log10(n)/log10(3));
    }
};
