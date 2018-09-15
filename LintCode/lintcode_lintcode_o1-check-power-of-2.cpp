/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        int cnt = 0;
        if(n < 0)
            return false;
        while(n){
            if(n&1)
                ++ cnt;
            n >>= 1;
        }
        return cnt == 1;
    }
};
