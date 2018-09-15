/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        if(n < 5) {
            return ans;
        }
        
        int p = 5;
        long long k = 5;
        while(n/k){
            ans += n/k;
            k *= p;
        }
        
        return ans;
    }
};
