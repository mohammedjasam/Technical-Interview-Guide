/*
*
* Tag: Implementation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int lastRemaining(int n) {
        int res = 1, cnt = 0, p = 1;
        while(n > 1){
            n >>= 1;
            p <<= 1;
            ++ cnt;
            if(cnt%2)
                res += p/2 + p*(n - 1);
            else
                res -= p/2 + p*(n - 1);
        }
        return res;
    }
};
