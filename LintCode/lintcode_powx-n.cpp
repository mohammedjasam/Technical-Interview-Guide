/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if(!n)
            return 1.0;
        if(fabs(x - 0.0) < 1e-3)
            return 0.0;
        double res = 1, val = x;
        bool isneg = false;
        if(n < 0){
            isneg = true;
            n = -n;
        }
        while(n){
            if(n&1){
                res*=val;
            }
            n>>=1;
            val*=val;
        }
        return isneg?1.0/res:res;
    }

};
