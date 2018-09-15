/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(lgn)
*/
class Solution {
public:
    /**
     * @param a: the given number
     * @param b: another number
     * @return: the greatest common divisor of two numbers
     */
    int gcd(int a, int b) {
        return b == 0? a : gcd(b, a%b);
    }
};
