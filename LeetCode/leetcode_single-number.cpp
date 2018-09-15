/*
*
* Tag: Bit Manipulation
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long hbit = 31, lbit = 0;
        long long high = 1LL<<hbit, low = 1LL<<lbit;
        while(hbit >= lbit){
            long long hres = n&high, lres = low&n;
            if((hres && !lres) || (!hres && lres)){
                n = n^high;
                n = n^low;
            }
            -- hbit;
            ++ lbit;
            high >>= 1;
            low <<= 1;
        }
        return n;
    }
};
