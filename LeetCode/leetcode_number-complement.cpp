/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int findComplement(int num) {
        int ans = 0, mask = 1;
        while(num){
            if((num&1) == 0)
                ans |= mask;
            num >>= 1;
            mask <<= 1;
        }
        return ans;
    }
};

class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while(num & mask) mask <<= 1;
        return ~num & ~mask;
    }
};
