/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        return !((n%3==0 && n) || !n);
    }
};
