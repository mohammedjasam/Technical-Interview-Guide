/*
*
* Tag: Bit Manipulation
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int c = a^b;
        int iter = 32;
        int cnt = 0;
        while(iter --){
            if(c&1)
                ++ cnt;
            c>>=1;
        }
        return cnt;
    }
};
