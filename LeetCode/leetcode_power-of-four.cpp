/*
*
* Tag: Bit Manipulation
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num&(num-1)) && ((num&1431655765)==num);
    }
};
