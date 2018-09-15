/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int v = x^y, res = 0;
        while(v > 0){
            if(v&1)
                ++ res;
            v >>= 1;
        }
        return res;
    }
};
