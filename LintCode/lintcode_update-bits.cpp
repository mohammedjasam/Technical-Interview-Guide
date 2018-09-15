/*
*
* Tag: Bit Manipulation
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int l = j-i+1;
        unsigned int mask = l==32 ? 0xffffffff : ((1<<l)-1);
        return (n & (~(mask<<i))) | ((m & mask) << i);
    }
};
