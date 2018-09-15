/*
*
* Tag: Bit Manipulation
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int cnt = 0;
        if(!num)
            return cnt;
        int bitnum = 32;
        while(num && bitnum){
            if(num&1){
                ++ cnt;
            }
            num>>=1;
            --bitnum;
        }
        return cnt;
    }
};
