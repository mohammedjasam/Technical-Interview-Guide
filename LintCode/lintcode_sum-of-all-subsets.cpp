/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    /*
     * @param : the given number
     * @return: Sum of elements in subsets
     */
    int subSum(int n) {
        return n <= 1? n : n*(n + 1)*(1<<(n - 2));
    }
};
