/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code h
        if(b < 0)
            return 0;
        if(a == 0 || a == 1)
            return a;
        if(n == 0 && b == 1)
            return 0;
        long long res = 1, base = a;
        while(n){
            if(n&1){
                res *= base;
                if(res < 0)
                    res = (res + b)%b;
                else
                    res = res%b;
            }
            n >>= 1;
            base = (base*base)%b;
        }
        return (int)res;
    }
};
