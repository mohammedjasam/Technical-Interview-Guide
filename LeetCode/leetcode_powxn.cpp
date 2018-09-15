/*
*
* Tag: Math
* Time : O(logn)
* Space : O(1)
*/
class Solution {
public:
    double myPow(double x, int _n) {
        long long n = _n;
        if(n == 0) {
            return 1.0;
        }
        if(n == 1) {
            return x;
        }
        
        bool isNegative = false;
        if(n < 0){
            n *= -1;
            isNegative = true;
        }
        
        double ans = 1.0, xpow = x;
        while(n > 0)
        {
            if((n&1) == 1){
                ans *= xpow;
            }
            
            n >>= 1;
            xpow *= xpow;
        }
        
        return isNegative ? 1/ans : ans;
    }
};
