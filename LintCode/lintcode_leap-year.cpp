/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param n: a number represent year
     * @return: whether year n is a leap year.
     */
    bool isLeapYear(int n) {
        return n%400 == 0 || (n%4 == 0 && n%100 != 0);
    }
};
