/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n <= 1){
            return true;
        }
        
        while(n > 0){
            if((n&1) == ((n>>1)&1)){
                return false;
            }
                        
            n >>= 1;
        }
        
        return true;
    }
};
